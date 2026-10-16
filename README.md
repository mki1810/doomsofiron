# Dooms of Iron

[![Hearts of Iron IV](https://img.shields.io/badge/HOI4-1.19.*-blue.svg)](https://store.steampowered.com/app/394360/Hearts_of_Iron_IV/)
[![Freedoom License](https://img.shields.io/badge/Freedoom-BSD--3--Clause-green.svg)](licenses/FREEDOOM-COPYING.txt)
[![DOOM Shareware License](https://img.shields.io/badge/DOOM_Shareware-id_Software_1993-red.svg)](licenses/DOOM-SHAREWARE-LICENSE.txt)
[![Engine License](https://img.shields.io/badge/Engine-GPL--2.0-orange.svg)](licenses/DOOMGENERIC-GPL.txt)
[![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)]()

> Играйте в легендарный шутер прямо во встроенном браузере Hearts of Iron IV.

---

## Русский

### О моде
Dooms of Iron интегрирует порт классического шутера прямо в браузер Hearts of Iron IV с поддержкой как оригинального классического DOOM, так и свободных фанатских кампаний.

* **Режимы игры на выбор прямо в меню:**
  * **DOOM 1 (1993)**: оригинальный исторический первый эпизод *«Knee-Deep in the Dead»* (E1M1 Hangar и все 9 уровней) под официальной Shareware-лицензией id Software.
  * **Freedoom: Phase 1**: 4 полных эпизода под свободной лицензией BSD-3-Clause.
  * **Freedoom: Phase 2**: 32 масштабных уровня в стиле Doom II под лицензией BSD-3-Clause.
* **Движок**: [doomgeneric](https://github.com/ozkl/doomgeneric) (лицензия GNU GPL-2.0, основан на коде id Software), скомпилированный в WebAssembly (Wasm) через Emscripten SDK. 35–60 FPS с поддержкой мыши, клавиатуры и звука.
* **Полностью автономен**: работает локально без подключения к интернету.
* **Встроенный нативный сервер**: `server.exe` (исходный код [web/server.c](web/server.c)) весит всего ~116 КБ и не требует установки Python.
* **Безопасен**: работает строго на изолированном адресе 127.0.0.1 (Loopback) без доступа из внешней сети.

---

### Как запустить

1. В лаунчере игры возле мода нажмите три точки `...` → **«Показать в папке»**.
2. Запустите **`server.exe`** прямо в открывшейся папке (он тихо включится в фоне и сам автоматически закроется после выхода из HOI4).
3. Нажимайте «Играть» в лаунчере.

---

### Лицензии и авторские права

Все полные тексты лицензий и манифестов собраны в отдельной папке [licenses/](licenses/):
* **Оригинальные данные DOOM 1 (`doom1.wad`)**: Официальная Shareware-лицензия id Software 1993 года (Association of Shareware Professionals). Разрешено свободное некоммерческое распространение оригинального файла первого эпизода. Подробнее: [licenses/DOOM-SHAREWARE-LICENSE.txt](licenses/DOOM-SHAREWARE-LICENSE.txt).
* **Данные Freedoom (`freedoom1.wad`, `freedoom2.wad`)**: Лицензия BSD (3-Clause). Авторские права принадлежат участникам проекта Freedoom (2001-2024). Текст: [licenses/FREEDOOM-COPYING.txt](licenses/FREEDOOM-COPYING.txt), авторы: [licenses/FREEDOOM-CREDITS.txt](licenses/FREEDOOM-CREDITS.txt).
* **Игровой движок (doomgeneric Wasm)**: Лицензия GNU General Public License v2 (GPL-2.0). Текст: [licenses/DOOMGENERIC-GPL.txt](licenses/DOOMGENERIC-GPL.txt). Исходный репозиторий: https://github.com/ozkl/doomgeneric. Исходный код DOOM принадлежит id Software (1993, 1997).
* **Локальный веб-сервер и скрипты мода**: Исходный код сервера открыт в [web/server.c](web/server.c).

---

<br>

---

## English

### About the Mod
Dooms of Iron brings the classic retro FPS experience directly into the Hearts of Iron IV in-game browser with support for both original classic DOOM and community campaigns.

* **Selectable Game Modes directly from topbar:**
  * **DOOM 1 (1993)**: Original authentic Episode 1 *«Knee-Deep in the Dead»* (E1M1 Hangar through E1M9) under the official 1993 id Software Shareware license.
  * **Freedoom: Phase 1**: 4 complete episodes under the BSD-3-Clause license.
  * **Freedoom: Phase 2**: 32 full Doom II style levels under the BSD-3-Clause license.
* **Engine**: [doomgeneric](https://github.com/ozkl/doomgeneric) (GNU GPL-2.0, based on id Software's DOOM source code), compiled to WebAssembly (Wasm) using Emscripten SDK. Real-time 35–60 FPS with full sound, keyboard & mouse controls.
* **Fully offline and self-contained**: No internet connection required.
* **Native microserver**: `server.exe` (source code in [web/server.c](web/server.c)) is ~116 KB, automatically closes when HOI4 exits.
* **Isolated and secure**: Strictly bound to local loopback (127.0.0.1), fully protected sandbox.

---

### How to Play

1. In the Paradox Launcher, click the three dots `...` next to the mod → **"Show in folder"**.
2. Run **`server.exe`** directly in the opened mod folder (it runs silently in the background and terminates automatically when HOI4 closes).
3. Hit "Play" in the launcher.

---

### Licenses & Legal Attribution

All full license texts and credits are organized in the [licenses/](licenses/) folder:
* **Original DOOM 1 Assets (`doom1.wad`)**: id Software 1993 Shareware License (Association of Shareware Professionals). Freely redistributable for non-commercial evaluation. See [licenses/DOOM-SHAREWARE-LICENSE.txt](licenses/DOOM-SHAREWARE-LICENSE.txt).
* **Freedoom Assets (`freedoom1.wad`, `freedoom2.wad`)**: Released under the BSD 3-Clause license. Copyright 2001-2024 contributors to the Freedoom project. See [licenses/FREEDOOM-COPYING.txt](licenses/FREEDOOM-COPYING.txt) and [licenses/FREEDOOM-CREDITS.txt](licenses/FREEDOOM-CREDITS.txt).
* **Game Engine (doomgeneric Wasm)**: Distributed under the GNU General Public License v2 (GPL-2.0). See [licenses/DOOMGENERIC-GPL.txt](licenses/DOOMGENERIC-GPL.txt). Upstream repository: https://github.com/ozkl/doomgeneric. DOOM is copyright 1993, 1997 id Software.
* **Local Web Server**: Source code is available in [web/server.c](web/server.c).
