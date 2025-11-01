# Genesis Game Engine

**Faulve Corps OPC. — 2025**

---

## Purpose
**Genesis Game Engine** is a **cross-platform, high-performance, modular C++ game engine** designed to let developers build and publish games on **Windows, Linux, and macOS**, with support planned for additional platforms.

It supports multiple **graphics, audio, and compute APIs**, allows developers to **expose game logic for modding**, and can be built **with or without an editor** — offering full control over performance, architecture, and distribution.

---

## Features

### 1. Cross-Platform Graphics & Compute
- **Graphics APIs:** DirectX (WinAPI, Windows-only), OpenGL, Vulkan  
- **Compute APIs:** OpenCL for heavy computation  
- **XR Support:** OpenXR  
- **Abstract API Layer:** Enables runtime selection or graceful fallback between backends  

### 2. Audio & Asset Management
- **Audio:** OpenAL  
- **3D Assets:** Assimp for model importing  
- **Custom Asset Pipeline:** Optimized formats for fast loading and runtime efficiency  

### 3. Moddability & Interoperability
- Expose selective game files, classes, methods, and variables for modding  
- Embed or interoperate with **Lua**, **Python**, or other scripting languages  
- Provide optional **language bindings** for C# or Java  

### 4. Single Executable Output
- Use **static linking** (`.lib` / `.a`) for engine and game libraries instead of many DLLs  
- Integrate projects in one **Visual Studio solution**  
- Output a single executable with minimal external dependencies  
- Optional editor; engine can be compiled **headless**  

### 5. Performance & Reliability
- Pure **native C++** for maximum speed and low-level control  
- Explicit memory management and optional multithreading  
- Supports **cross-language interop** for custom or external game code  

---

## Core Architecture

```

/Engine
  /Core
    - Windowing & Input (SDL3)
    - Rendering (DirectX / OpenGL / Vulkan abstraction)
    - Audio (OpenAL)
    - Physics (BulletPhysics)
    - ECS (EnTT)
    - Scripting API (Lua/Python/C# interop hooks)
    - Asset Management (Assimp + optimized formats)
  /Utils
    - Math (vec/mat/quat)
    - Logging & Debugging
    - Profiling Tools
  /Game
    - Game Logic (static lib / dynamic module)
    - Levels / Scenes
    - Exposed Modding API
  /Launcher
    - Game Loader / Bootstrapper
    - Optional Editor
    - Build & Export Tools
  /Tools
    - Shader Compiler / Preprocessor
    - Asset Converter / Packer
    - Packaging Scripts (single-exe or installer)

```

---

## Development Outline

### 1. Abstract Graphics Layer
- Interface: `IGraphicsAPI`
  - `bool Init(WindowHandle, GraphicsConfig)`
  - `void SetViewport(...)`, `SetShader(...)`, `DrawMesh(...)`, `SwapBuffers()`
- Backends:
  - `DirectXRenderer` (Windows-only)
  - `VulkanRenderer` (cross-platform)
  - `OpenGLRenderer` (compatibility)
- Keeps backend-specific code isolated behind a unified interface.

### 2. Hot-Reload / Modding
- Load game logic as `.dll` / `.so` modules during development for **hot-swapping**  
- Static linking for release builds  
- Provide versioned **C/C++ plugin interface** and SDK headers for modders  

### 3. Profiling & Debugging Tools
- **ImGui** integration for runtime overlays (FPS, memory, draw calls, GPU timings)  
- Lightweight **logging** and **performance counters**

### 4. Asset Bundling & Executable Packaging
- Use static linking where practical  
- Create `.pak` or `.ggpak` **binary asset containers**  
- Optionally embed small assets (shaders, icons) directly into executables  

### 5. Cross-Platform Considerations
- **SDL3** for windowing and input  
- **CMake** for builds (Visual Studio, Makefiles, Xcode)  
- Conditional compilation:
  - `#ifdef _WIN32` → DirectX  
  - macOS → MoltenVK / Metal (future)  
  - Linux → Vulkan / OpenGL  

---

## Phased Development Plan

| Phase | Focus | Description |
|:------|:------|:-------------|
| **1** | Core Systems | Windowing, Input (SDL3), Renderer (Vulkan/OpenGL), Audio, ECS |
| **2** | Backends | Add DirectX, OpenCL, and OpenXR support |
| **3** | Modding & Editor | Plugin/mod system, editor prototype, single-exe export |
| **4** | Scripting & Runtime | Cross-language scripting, hot-reload, documentation, samples |

---

## Project Layout (Visual Studio / CMake Friendly)

```

/root
  /Engine
    /Core (static lib)
      /Renderers
      /VulkanRenderer
      /OpenGLRenderer
      /DirectXRenderer (Windows-only)
    /ThirdParty (Assimp, SDL3, OpenAL, Bullet, EnTT, ImGui)
    /Utils
  /GameProjects
    /SampleGame (links Engine libs)
  /Launcher (executable)
  /Editor (optional)
  /Tools
    - asset_packer
    - shader_compiler
CMakeLists.txt
docs/
LICENSE
README.md

```

---

## Build & Tooling Recommendations
- **CMake** as the main build system (generate Visual Studio, Xcode, or Makefile projects)  
- Use `find_package()` for third-party dependencies (SDL3, Assimp, Bullet, etc.)  
- **CI Integration:** GitHub Actions or Azure Pipelines for cross-platform builds  
- Provide prebuilt **Engine SDK** (headers + static libs) for quick setup  

---

## Performance & Safety Practices
- Use **RAII** and custom allocators in performance-critical systems  
- Provide **safe defaults**: debug assertions, release optimizations  
- Offer **profiling markers** (CPU/GPU timing) via renderer hooks  
- Minimize ABI issues by versioning plugin interfaces  

---

## Initial TODO (First 6–12 Weeks)
1. Set up repository & CI with LICENSE and README  
2. Build minimal Core: SDL3 window + input, Vulkan/OpenGL renderer  
3. Integrate Assimp for model loading and rendering  
4. Implement ECS (EnTT) and simple scene with one moving entity  
5. Add ImGui overlay for debugging  
6. Prototype asset packing tool (pack/unpack shaders & textures)

---

## Risks & Tradeoffs
- **Scope Creep:** Focus on minimal viable core before expanding  
- **ABI Stability vs Convenience:** Maintain versioned plugin SDK  
- **Platform Specifics:** DirectX and Metal require dedicated handling  

---

## License
© 2025 **Faulve Corps OPC.**  
All rights reserved.  
Future releases may adopt a custom license such as **GENESIS-SA-NC-2.0** or similar.

---

## Vision
The **Genesis Game Engine** strives to be:
> “A truly modern, modular, and moddable game engine — unifying performance, portability, and creative freedom in one C++ ecosystem.”

---
