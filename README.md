# Dooms of Iron

[![Hearts of Iron IV](https://img.shields.io/badge/HOI4-1.19.*-blue.svg)](https://store.steampowered.com/app/394360/Hearts_of_Iron_IV/)
[![Freedoom License](https://img.shields.io/badge/Data-BSD--3--Clause-green.svg)](COPYING.txt)
[![Engine License](https://img.shields.io/badge/Engine-GPL--2.0-orange.svg)](LICENSE-GPL.txt)
[![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)]()

> Играйте в классический шутер прямо во встроенном браузере Hearts of Iron IV.

---

## Русский

### О моде
Dooms of Iron интегрирует порт классического шутера прямо в браузер Hearts of Iron IV.

* Движок: [doomgeneric](https://github.com/ozkl/doomgeneric) (лицензия GNU GPL-2.0, основан на исходном коде DOOM от id Software), скомпилированный в WebAssembly (Wasm) через Emscripten SDK.
* Игровые данные: ресурсы открытого проекта [Freedoom](https://freedoom.github.io/) Phase 1 (4 эпизода) и Phase 2 (32 уровня) под лицензией BSD 3-Clause.
* Полностью автономен — работает локально без интернета.
* Встроенный нативный сервер (`server.exe`, исходный код [server.c](server.c)) весит всего ~116 КБ и не требует установки Python.
* Безопасен: работает строго на изолированном адресе 127.0.0.1 (Loopback) без доступа из внешней сети.

---

### Как запустить

1. В лаунчере игры возле мода нажмите три точки `...` → **«Показать в папке»**.
2. В открывшейся папке перейдите в `web` и запустите **`server.exe`** (он тихо включится в фоне). Исходный код сервера доступен в файле [server.c](server.c).
3. Нажимайте «Играть» в лаунчере.

---

### Лицензии и авторские права
* **Игровые данные (WAD)**: Проект Freedoom распространяется под модифицированной лицензией BSD (3-Clause). Авторские права принадлежат участникам проекта Freedoom (2001-2024). Полный текст лицензии доступен в файле [COPYING.txt](COPYING.txt), список авторов — в [CREDITS.txt](CREDITS.txt).
* **Игровой движок**: Исходный код doomgeneric распространяется под лицензией GNU General Public License v2. Текст лицензии доступен в файле [LICENSE-GPL.txt](LICENSE-GPL.txt). Исходный репозиторий: https://github.com/ozkl/doomgeneric. Исходный код DOOM принадлежит id Software (1993, 1997).
* **Сборка WebAssembly**: Скомпилирована из doomgeneric с использованием Emscripten (`emcc`).
* **Локальный веб-сервер**: Исходный код предоставлен в открытом виде в [server.c](server.c) и [web/server.c](web/server.c).

---

<br>

---

## English

### About the Mod
Dooms of Iron brings the classic retro FPS experience directly into the Hearts of Iron IV in-game browser.

* Engine: [doomgeneric](https://github.com/ozkl/doomgeneric) (GNU GPL-2.0, based on id Software's DOOM source code), compiled to WebAssembly (Wasm) using Emscripten SDK.
* Game Assets: [Freedoom](https://freedoom.github.io/) Phase 1 (4 episodes) and Phase 2 (32 levels) under the BSD 3-Clause License.
* Fully offline and self-contained: No internet connection required.
* Native microserver (`server.exe`, source code in [server.c](server.c)) is ~116 KB and requires no Python installation.
* Isolated and secure: Strictly bound to local loopback (127.0.0.1), fully protected sandbox.

---

### How to Play

1. In the Paradox Launcher, click the three dots `...` next to the mod → **"Show in folder"**.
2. Open the `web` folder and run **`server.exe`** (it runs silently in the background). Source code is available in [server.c](server.c).
3. Hit "Play" in the launcher.

---

### Licenses & Credits
* **Game Assets (WAD)**: Freedoom is released under the modified BSD (3-Clause) license. Copyright 2001-2024 by contributors to the Freedoom project. See [COPYING.txt](COPYING.txt) for license terms and [CREDITS.txt](CREDITS.txt) for contributors.
* **Game Engine**: The doomgeneric source port is distributed under the GNU General Public License v2. See [LICENSE-GPL.txt](LICENSE-GPL.txt). Upstream repository: https://github.com/ozkl/doomgeneric. DOOM is copyright 1993, 1997 id Software.
* **WebAssembly Build**: Compiled from doomgeneric source using the Emscripten toolchain (`emcc`).
* **Local Web Server**: The source code is open and available in [server.c](server.c) and [web/server.c](web/server.c).
