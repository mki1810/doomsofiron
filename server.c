#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8000
#define BUFFER_SIZE 65536

static void UrlDecode(char *dst, const char *src) {
    char a, b;
    while (*src) {
        if ((*src == '%') &&
            ((a = src[1]) && (b = src[2])) &&
            (isxdigit(a) && isxdigit(b))) {
            if (a >= 'a') a -= 'a' - 'A';
            if (a >= 'A') a -= ('A' - 10);
            else a -= '0';
            if (b >= 'a') b -= 'a' - 'A';
            if (b >= 'A') b -= ('A' - 10);
            else b -= '0';
            *dst++ = 16 * a + b;
            src += 3;
        } else if (*src == '+') {
            *dst++ = ' ';
            src++;
        } else {
            *dst++ = *src++;
        }
    }
    *dst = '\0';
}

static int IsProcessRunning(const wchar_t *processName) {
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnap == INVALID_HANDLE_VALUE) return 0;
    
    PROCESSENTRY32W pe;
    pe.dwSize = sizeof(pe);
    int found = 0;
    if (Process32FirstW(hSnap, &pe)) {
        do {
            if (_wcsicmp(pe.szExeFile, processName) == 0) {
                found = 1;
                break;
            }
        } while (Process32NextW(hSnap, &pe));
    }
    CloseHandle(hSnap);
    return found;
}

static DWORD WINAPI Hoi4WatcherThread(LPVOID param) {
    int started = 0;
    for (int i = 0; i < 150; i++) {
        if (IsProcessRunning(L"hoi4.exe")) {
            started = 1;
            break;
        }
        Sleep(2000);
    }
    
    if (!started) {
        ExitProcess(0);
    }
    
    while (1) {
        Sleep(3000);
        if (!IsProcessRunning(L"hoi4.exe")) {
            ExitProcess(0);
        }
    }
    return 0;
}

static DWORD WINAPI HandleClient(LPVOID param) {
    SOCKET client_sock = (SOCKET)param;
    char req_buf[4096];
    int bytes_recv = recv(client_sock, req_buf, sizeof(req_buf) - 1, 0);
    if (bytes_recv <= 0) {
        closesocket(client_sock);
        return 0;
    }
    req_buf[bytes_recv] = '\0';
    
    char method[16], raw_path[1024];
    if (sscanf(req_buf, "%15s %1023s", method, raw_path) < 2) {
        closesocket(client_sock);
        return 0;
    }
    
    if (_stricmp(method, "GET") != 0 && _stricmp(method, "HEAD") != 0) {
        const char *err405 = "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\nConnection: close\r\n\r\n";
        send(client_sock, err405, (int)strlen(err405), 0);
        closesocket(client_sock);
        return 0;
    }
    
    char *q = strchr(raw_path, '?');
    if (q) *q = '\0';
    
    char decoded_path[1024];
    UrlDecode(decoded_path, raw_path);
    
    const char *file_path = decoded_path;
    if (strcmp(file_path, "/") == 0) {
        file_path = "/index.html";
    }
    while (file_path[0] == '/') file_path++;
    
    if (strstr(file_path, "..") || strchr(file_path, ':') || strchr(file_path, '\\')) {
        const char *err403 = "HTTP/1.1 403 Forbidden\r\nContent-Length: 0\r\nConnection: close\r\n\r\n";
        send(client_sock, err403, (int)strlen(err403), 0);
        closesocket(client_sock);
        return 0;
    }
    
    const char *mime = NULL;
    const char *dot = strrchr(file_path, '.');
    if (dot) {
        if (_stricmp(dot, ".html") == 0 || _stricmp(dot, ".htm") == 0) mime = "text/html; charset=utf-8";
        else if (_stricmp(dot, ".js") == 0) mime = "application/javascript; charset=utf-8";
        else if (_stricmp(dot, ".wasm") == 0) mime = "application/wasm";
        else if (_stricmp(dot, ".css") == 0) mime = "text/css; charset=utf-8";
        else if (_stricmp(dot, ".data") == 0) mime = "application/octet-stream";
        else if (_stricmp(dot, ".wad") == 0) mime = "application/octet-stream";
        else if (_stricmp(dot, ".png") == 0) mime = "image/png";
        else if (_stricmp(dot, ".ico") == 0) mime = "image/x-icon";
    }
    
    if (!mime) {
        const char *err403 = "HTTP/1.1 403 Forbidden\r\nContent-Length: 0\r\nConnection: close\r\n\r\n";
        send(client_sock, err403, (int)strlen(err403), 0);
        closesocket(client_sock);
        return 0;
    }
    
    FILE *f = fopen(file_path, "rb");
    if (!f) {
        const char *err404 = "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\nConnection: close\r\n\r\n";
        send(client_sock, err404, (int)strlen(err404), 0);
        closesocket(client_sock);
        return 0;
    }
    
    _fseeki64(f, 0, SEEK_END);
    __int64 file_size = _ftelli64(f);
    _fseeki64(f, 0, SEEK_SET);
    
    char header[1024];
    int hlen = sprintf(header,
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: %s\r\n"
        "Content-Length: %lld\r\n"
        "Cache-Control: no-cache, no-store, must-revalidate\r\n"
        "Pragma: no-cache\r\n"
        "Expires: 0\r\n"
        "Connection: close\r\n\r\n",
        mime, file_size
    );
    send(client_sock, header, hlen, 0);
    
    if (_stricmp(method, "HEAD") == 0) {
        fclose(f);
        closesocket(client_sock);
        return 0;
    }
    
    char *chunk = (char*)malloc(BUFFER_SIZE);
    if (chunk) {
        size_t read_bytes;
        while ((read_bytes = fread(chunk, 1, BUFFER_SIZE, f)) > 0) {
            int total_sent = 0;
            while (total_sent < (int)read_bytes) {
                int sent = send(client_sock, chunk + total_sent, (int)read_bytes - total_sent, 0);
                if (sent <= 0) break;
                total_sent += sent;
            }
            if (total_sent < (int)read_bytes) break;
        }
        free(chunk);
    }
    
    fclose(f);
    closesocket(client_sock);
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    wchar_t exePath[MAX_PATH];
    GetModuleFileNameW(NULL, exePath, MAX_PATH);
    wchar_t *lastSlash = wcsrchr(exePath, L'\\');
    if (lastSlash) {
        *lastSlash = L'\0';
        SetCurrentDirectoryW(exePath);
    }
    
    DWORD attr = GetFileAttributesW(L"web");
    if (attr != INVALID_FILE_ATTRIBUTES && (attr & FILE_ATTRIBUTE_DIRECTORY)) {
        SetCurrentDirectoryW(L"web");
    }
    
    if (!strstr(lpCmdLine, "--no-watch") && !strstr(lpCmdLine, "-nowatch")) {
        CreateThread(NULL, 0, Hoi4WatcherThread, NULL, 0, NULL);
    }
    
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        return 1;
    }
    
    SOCKET server_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_fd == INVALID_SOCKET) {
        WSACleanup();
        return 1;
    }
    
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        closesocket(server_fd);
        WSACleanup();
        return 0;
    }
    
    if (listen(server_fd, 64) == SOCKET_ERROR) {
        closesocket(server_fd);
        WSACleanup();
        return 1;
    }
    
    while (1) {
        struct sockaddr_in client_addr;
        int client_len = sizeof(client_addr);
        SOCKET client_sock = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
        if (client_sock != INVALID_SOCKET) {
            HANDLE hThread = CreateThread(NULL, 0, HandleClient, (LPVOID)client_sock, 0, NULL);
            if (hThread) CloseHandle(hThread);
            else closesocket(client_sock);
        }
    }
    
    closesocket(server_fd);
    WSACleanup();
    return 0;
}
