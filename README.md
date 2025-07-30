# Genesis Game Engine

<p align="center">
   <img width="800" height="400" alt="GenesisGameEngineRevamped" src="https://github.com/user-attachments/assets/2c64cc50-b39d-439e-9aa3-522d39f7f4b2" />
</p>

A cross-platform, modular, and embeddable 2D/3D game engine built in modern C++.

> **Disclaimer:** This project is protected by the GENESIS-SA-NC-2.3 License.  
> Usage is subject to the terms and conditions outlined in that license.  
> No commercial use is permitted without explicit permission.

**Goals:**
- Portable across Desktop, Mobile, and Web
- Cross-Graphics API (OpenGL, Vulkan, Metal, D3D via bgfx)
- Clean architecture separating Engine, Game, and Executable
- Runtime scripting, editor-ready, and lightweight

---

## Architecture Overview

```
Genesis/
├── Engine/ <- Core engine modules (Rendering, Physics, Audio, etc.)
├── Game/ <- Game logic and assets
├── Executable/ <- Platform-specific launcher / glue code
├── External/ <- 3rd party libraries
├── CMake/ <- CMake configuration
└── Assets/ <- Common assets (textures, sounds, models)
```
---

## Dependencies (Cross-Platform Ready)

| Library           | Purpose                        | Platforms Supported |
|-------------------|--------------------------------|---------------------|
| [SDL3](https://github.com/libsdl-org/SDL)          | Platform abstraction (window, input, audio) | ✅ Win / Linux / macOS / Android / iOS / Web |
| [bgfx](https://github.com/bkaradzic/bgfx)          | Renderer backend abstraction                | ✅ Win / Linux / macOS / Android / iOS / Web |
| [Bullet Physics](https://github.com/bulletphysics/bullet3) | 3D Physics + Collision                    | ✅ Win / Linux / macOS / Android / iOS |
| [EnTT](https://github.com/skypjack/entt)           | Entity Component System (ECS)              | ✅ All Platforms |
| [GLM](https://github.com/g-truc/glm)               | Math library for 3D/2D math                | ✅ All Platforms |
| [miniaudio](https://github.com/mackron/miniaudio)  | Audio engine (music, SFX, streaming)       | ✅ All Platforms |
| [stb_image](https://github.com/nothings/stb)       | Image loading (PNG, JPG, etc.)             | ✅ All Platforms |
| [nlohmann/json](https://github.com/nlohmann/json)  | JSON parsing                               | ✅ All Platforms |
| [Dear ImGui](https://github.com/ocornut/imgui)     | In-engine debug/editor GUI                 | ✅ All Platforms |
| [spdlog](https://github.com/gabime/spdlog)         | Logging system                             | ✅ All Platforms |
| [PhysFS](https://github.com/icculus/physfs)        | Virtual file system (ZIP, PAK)             | ✅ All Platforms |
| [Tracy](https://github.com/wolfpld/tracy)          | Real-time frame profiler                   | ✅ Win / Linux / macOS |

---

## Features (Planned)

- ✅ Multi-platform rendering (OpenGL, Vulkan, Metal, D3D)
- ✅ Modular architecture
- ✅ ECS-based scene management
- ✅ Asset loading and virtual file system
- ✅ Audio playback with spatialization
- ✅ JSON-based serialization
- ✅ Debug tools (console, ImGui, profiler)
- 🔄 Live reloading system
- 🧠 Lua scripting integration *(planned)*
- 🛠️ Scene Editor *(planned)*

---

## Build Instructions

### Requirements:
- CMake 3.20+
- C++17 Compiler (MSVC, Clang, GCC)
- Git

### Steps:
```bash
git clone --recursive https://github.com/FaulveCorps/Genesis.git
cd Genesis
mkdir build && cd build
cmake ..
cmake --build . --config Release
```
Use ``-DGENESIS_BUILD_EXAMPLES=ON`` to build demo scenes and test apps.
