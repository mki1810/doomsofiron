# Dooms of Iron

[![Hearts of Iron IV](https://img.shields.io/badge/HOI4-1.19.*-blue.svg)](https://store.steampowered.com/app/394360/Hearts_of_Iron_IV/)
[![License: BSD-3-Clause](https://img.shields.io/badge/License-Freedoom%20BSD-green.svg)](https://freedoom.github.io/)
[![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)]()

> Играйте в классический шутер прямо во встроенном браузере Hearts of Iron IV.

---

## Русский

### О моде
Dooms of Iron интегрирует порт классического шутера (на базе движка Freedoom Phase 1 и Phase 2) прямо в меню Hearts of Iron IV.

* Полностью автономен — работает локально без интернета.
* Поддерживает обе части: Freedoom: Phase 1 (4 эпизода) и Freedoom: Phase 2 (32 уровня).
* Встроенный нативный сервер (~116 КБ) — не требует установки Python.
* Безопасен: работает строго на изолированном адресе 127.0.0.1 (Loopback) без доступа из внешней сети.

---

### Как запустить

1. В лаунчере игры возле мода нажмите три точки `...` → **«Показать в папке»**.
2. В открывшейся папке перейдите в `web` и запустите **`server.exe`** (он тихо включится в фоне).
3. Нажимайте «Играть» в лаунчере.

---

<br>

---

## English

### About the Mod
Dooms of Iron brings the classic retro FPS experience (Freedoom Phase 1 & 2) directly into the Hearts of Iron IV in-game browser.

* Fully offline and self-contained: No internet connection required.
* Dual Episode Support: Switch between Phase 1 (4 episodes) and Phase 2 (32 levels) with a single click.
* Native microserver (~116 KB): Zero dependencies, no Python installation required.
* Isolated and secure: Strictly bound to local loopback (127.0.0.1), fully protected sandbox.

---

### How to Play

1. In the Paradox Launcher, click the three dots `...` next to the mod → **"Show in folder"**.
2. Open the `web` folder and run **`server.exe`** (it runs silently in the background).
3. Hit "Play" in the launcher.

---

### Security and Privacy
* The bundled server.exe binds exclusively to 127.0.0.1 (INADDR_LOOPBACK).
* It is physically inaccessible from your local network or the internet.
* Read-only sandbox: requests with path traversal (`..` or `:`) or unauthorized file types are strictly blocked (403 Forbidden).
