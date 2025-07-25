# Genesis - v2 Revision - Dead End (Abandoned)
```
Microsoft Windows [Version 10.0.17763.107]
(c) 2018 Microsoft Corporation. All rights reserved.

C:\Users\[Redacted]\Desktop\Genesis>Build
[Genesis Build] Cloning Necessary Repositories...
[Genesis Build] SDL submodule already exists.
[Genesis Build] Json submodule already exists.
[Genesis Build] Glfw submodule already exists.
[Genesis Build] Glad submodule already exists.
[Genesis Build] Building SDL3 (static)...
-- Selecting Windows SDK version 10.0.26100.0 to target Windows 10.0.17763.
-- Could NOT find PkgConfig (missing: PKG_CONFIG_EXECUTABLE)
-- Could NOT find LibUSB (missing: LibUSB_LIBRARY LibUSB_INCLUDE_PATH) (found version "LibUSB_VERSION-NOTFOUND")
--
-- SDL3 was configured with the following options:
--
-- Platform: Windows-10.0.17763
-- 64-bit:   TRUE
-- Compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/cl.exe
-- Revision: SDL3-3.3.0-release-3.2.6-821-ge5d57d8ad
-- Vendor:
--
-- Subsystems:
--   Audio:    ON
--   Video:    ON
--   GPU:      ON
--   Render:   ON
--   Camera:   ON
--   Joystick: ON
--   Haptic:   ON
--   Hidapi:   ON
--   Power:    ON
--   Sensor:   ON
--   Dialog:   ON
--
-- Options:
--   SDL_ALSA                    (Wanted: OFF): OFF
--   SDL_ALSA_SHARED             (Wanted: OFF): OFF
--   SDL_ALTIVEC                 (Wanted: OFF): OFF
--   SDL_ARMNEON                 (Wanted: OFF): OFF
--   SDL_ASAN                    (Wanted: OFF): OFF
--   SDL_ASSEMBLY                (Wanted: ON): ON
--   SDL_ASSERTIONS              (Wanted: auto): auto
--   SDL_AVX                     (Wanted: ON): ON
--   SDL_AVX2                    (Wanted: ON): ON
--   SDL_AVX512F                 (Wanted: ON): ON
--   SDL_BACKGROUNDING_SIGNAL    (Wanted: OFF): OFF
--   SDL_CCACHE                  (Wanted: OFF): OFF
--   SDL_CLANG_TIDY              (Wanted: OFF): OFF
--   SDL_CLOCK_GETTIME           (Wanted: OFF): OFF
--   SDL_COCOA                   (Wanted: OFF): OFF
--   SDL_DBUS                    (Wanted: OFF): OFF
--   SDL_DEPS_SHARED             (Wanted: ON): OFF
--   SDL_DIRECTX                 (Wanted: ON): ON
--   SDL_DISKAUDIO               (Wanted: ON): ON
--   SDL_DUMMYAUDIO              (Wanted: ON): ON
--   SDL_DUMMYCAMERA             (Wanted: ON): ON
--   SDL_DUMMYVIDEO              (Wanted: ON): ON
--   SDL_EXAMPLES                (Wanted: OFF): OFF
--   SDL_EXAMPLES_LINK_SHARED    (Wanted: OFF): OFF
--   SDL_FOREGROUNDING_SIGNAL    (Wanted: OFF): OFF
--   SDL_GCC_ATOMICS             (Wanted: OFF): OFF
--   SDL_GPU_DXVK                (Wanted: OFF): OFF
--   SDL_HIDAPI                  (Wanted: ON): ON
--   SDL_HIDAPI_JOYSTICK         (Wanted: ON): ON
--   SDL_HIDAPI_LIBUSB           (Wanted: ON): OFF
--   SDL_HIDAPI_LIBUSB_SHARED    (Wanted: ON): OFF
--   SDL_IBUS                    (Wanted: OFF): OFF
--   SDL_INSTALL                 (Wanted: ON): OFF
--   SDL_INSTALL_TESTS           (Wanted: OFF): OFF
--   SDL_JACK                    (Wanted: OFF): OFF
--   SDL_JACK_SHARED             (Wanted: OFF): OFF
--   SDL_KMSDRM                  (Wanted: OFF): OFF
--   SDL_KMSDRM_SHARED           (Wanted: OFF): OFF
--   SDL_LASX                    (Wanted: OFF): OFF
--   SDL_LIBC                    (Wanted: ON): ON
--   SDL_LIBICONV                (Wanted: OFF): OFF
--   SDL_LIBUDEV                 (Wanted: ON): OFF
--   SDL_LIBURING                (Wanted: OFF): OFF
--   SDL_LSX                     (Wanted: OFF): OFF
--   SDL_METAL                   (Wanted: OFF): OFF
--   SDL_MMX                     (Wanted: ON): OFF
--   SDL_OFFSCREEN               (Wanted: ON): ON
--   SDL_OPENGL                  (Wanted: ON): ON
--   SDL_OPENGLES                (Wanted: ON): ON
--   SDL_OPENVR                  (Wanted: OFF): OFF
--   SDL_OSS                     (Wanted: OFF): OFF
--   SDL_PIPEWIRE                (Wanted: OFF): OFF
--   SDL_PIPEWIRE_SHARED         (Wanted: OFF): OFF
--   SDL_PTHREADS                (Wanted: OFF): OFF
--   SDL_PTHREADS_SEM            (Wanted: OFF): OFF
--   SDL_PULSEAUDIO              (Wanted: OFF): OFF
--   SDL_PULSEAUDIO_SHARED       (Wanted: OFF): OFF
--   SDL_RENDER_D3D              (Wanted: ON): ON
--   SDL_RENDER_D3D11            (Wanted: ON): ON
--   SDL_RENDER_D3D12            (Wanted: ON): ON
--   SDL_RENDER_GPU              (Wanted: ON): ON
--   SDL_RENDER_METAL            (Wanted: ON): OFF
--   SDL_RENDER_VULKAN           (Wanted: ON): ON
--   SDL_ROCKCHIP                (Wanted: OFF): OFF
--   SDL_RPATH                   (Wanted: OFF): OFF
--   SDL_RPI                     (Wanted: OFF): OFF
--   SDL_SNDIO                   (Wanted: OFF): OFF
--   SDL_SNDIO_SHARED            (Wanted: OFF): OFF
--   SDL_SSE                     (Wanted: ON): ON
--   SDL_SSE2                    (Wanted: ON): ON
--   SDL_SSE3                    (Wanted: ON): ON
--   SDL_SSE4_1                  (Wanted: ON): ON
--   SDL_SSE4_2                  (Wanted: ON): ON
--   SDL_SYSTEM_ICONV            (Wanted: OFF): OFF
--   SDL_TESTS                   (Wanted: OFF): OFF
--   SDL_TESTS_LINK_SHARED       (Wanted: OFF): OFF
--   SDL_UNINSTALL               (Wanted: ON): OFF
--   SDL_VIRTUAL_JOYSTICK        (Wanted: ON): ON
--   SDL_VIVANTE                 (Wanted: OFF): OFF
--   SDL_VULKAN                  (Wanted: ON): ON
--   SDL_WASAPI                  (Wanted: ON): ON
--   SDL_WAYLAND                 (Wanted: OFF): OFF
--   SDL_WAYLAND_LIBDECOR        (Wanted: OFF): OFF
--   SDL_WAYLAND_LIBDECOR_SHARED (Wanted: OFF): OFF
--   SDL_WAYLAND_SHARED          (Wanted: OFF): OFF
--   SDL_X11                     (Wanted: OFF): OFF
--   SDL_X11_SHARED              (Wanted: OFF): OFF
--   SDL_X11_XCURSOR             (Wanted: OFF): OFF
--   SDL_X11_XDBE                (Wanted: OFF): OFF
--   SDL_X11_XFIXES              (Wanted: OFF): OFF
--   SDL_X11_XINPUT              (Wanted: OFF): OFF
--   SDL_X11_XRANDR              (Wanted: OFF): OFF
--   SDL_X11_XSCRNSAVER          (Wanted: OFF): OFF
--   SDL_X11_XSHAPE              (Wanted: OFF): OFF
--   SDL_X11_XSYNC               (Wanted: OFF): OFF
--   SDL_X11_XTEST               (Wanted: OFF): OFF
--   SDL_XINPUT                  (Wanted: ON): ON
--
--  Build Shared Library: OFF
--  Build Static Library: ON
--
-- Configuring done (0.9s)
-- Generating done (0.3s)
-- Build files have been written to: C:/Users/[Redacted]/Desktop/Genesis/External/SDL/build
MSBuild version 17.14.10+8b8e13593 for .NET Framework

  SDL_uclibc.vcxproj -> C:\Users\[Redacted]\Desktop\Genesis\External\SDL\build\Release\SDL_uclibc.lib
  SDL3-static.vcxproj -> C:\Users\[Redacted]\Desktop\Genesis\External\SDL\build\Release\SDL3-static.lib
  SDL3_test.vcxproj -> C:\Users\[Redacted]\Desktop\Genesis\External\SDL\build\Release\SDL3_test.lib
[Genesis Build] Configuring Genesis CMake...
-- Selecting Windows SDK version 10.0.26100.0 to target Windows 10.0.17763.
-- Could NOT find PkgConfig (missing: PKG_CONFIG_EXECUTABLE)
-- Could NOT find LibUSB (missing: LibUSB_LIBRARY LibUSB_INCLUDE_PATH) (found version "LibUSB_VERSION-NOTFOUND")
--
-- SDL3 was configured with the following options:
--
-- Platform: Windows-10.0.17763
-- 64-bit:   TRUE
-- Compiler: C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/cl.exe
-- Revision: SDL3-3.3.0-release-3.2.6-821-ge5d57d8ad
-- Vendor:
--
-- Subsystems:
--   Audio:    ON
--   Video:    ON
--   GPU:      ON
--   Render:   ON
--   Camera:   ON
--   Joystick: ON
--   Haptic:   ON
--   Hidapi:   ON
--   Power:    ON
--   Sensor:   ON
--   Dialog:   ON
--
-- Options:
--   SDL_ALSA                    (Wanted: OFF): OFF
--   SDL_ALSA_SHARED             (Wanted: OFF): OFF
--   SDL_ALTIVEC                 (Wanted: OFF): OFF
--   SDL_ARMNEON                 (Wanted: OFF): OFF
--   SDL_ASAN                    (Wanted: OFF): OFF
--   SDL_ASSEMBLY                (Wanted: ON): ON
--   SDL_ASSERTIONS              (Wanted: auto): auto
--   SDL_AVX                     (Wanted: ON): ON
--   SDL_AVX2                    (Wanted: ON): ON
--   SDL_AVX512F                 (Wanted: ON): ON
--   SDL_BACKGROUNDING_SIGNAL    (Wanted: OFF): OFF
--   SDL_CCACHE                  (Wanted: OFF): OFF
--   SDL_CLANG_TIDY              (Wanted: OFF): OFF
--   SDL_CLOCK_GETTIME           (Wanted: OFF): OFF
--   SDL_COCOA                   (Wanted: OFF): OFF
--   SDL_DBUS                    (Wanted: OFF): OFF
--   SDL_DEPS_SHARED             (Wanted: ON): OFF
--   SDL_DIRECTX                 (Wanted: ON): ON
--   SDL_DISKAUDIO               (Wanted: ON): ON
--   SDL_DUMMYAUDIO              (Wanted: ON): ON
--   SDL_DUMMYCAMERA             (Wanted: ON): ON
--   SDL_DUMMYVIDEO              (Wanted: ON): ON
--   SDL_EXAMPLES                (Wanted: OFF): OFF
--   SDL_EXAMPLES_LINK_SHARED    (Wanted: OFF): OFF
--   SDL_FOREGROUNDING_SIGNAL    (Wanted: OFF): OFF
--   SDL_GCC_ATOMICS             (Wanted: OFF): OFF
--   SDL_GPU_DXVK                (Wanted: OFF): OFF
--   SDL_HIDAPI                  (Wanted: ON): ON
--   SDL_HIDAPI_JOYSTICK         (Wanted: ON): ON
--   SDL_HIDAPI_LIBUSB           (Wanted: ON): OFF
--   SDL_HIDAPI_LIBUSB_SHARED    (Wanted: ON): OFF
--   SDL_IBUS                    (Wanted: OFF): OFF
--   SDL_INSTALL                 (Wanted: OFF): OFF
--   SDL_INSTALL_TESTS           (Wanted: OFF): OFF
--   SDL_JACK                    (Wanted: OFF): OFF
--   SDL_JACK_SHARED             (Wanted: OFF): OFF
--   SDL_KMSDRM                  (Wanted: OFF): OFF
--   SDL_KMSDRM_SHARED           (Wanted: OFF): OFF
--   SDL_LASX                    (Wanted: OFF): OFF
--   SDL_LIBC                    (Wanted: ON): ON
--   SDL_LIBICONV                (Wanted: OFF): OFF
--   SDL_LIBUDEV                 (Wanted: ON): OFF
--   SDL_LIBURING                (Wanted: OFF): OFF
--   SDL_LSX                     (Wanted: OFF): OFF
--   SDL_METAL                   (Wanted: OFF): OFF
--   SDL_MMX                     (Wanted: ON): OFF
--   SDL_OFFSCREEN               (Wanted: ON): ON
--   SDL_OPENGL                  (Wanted: ON): ON
--   SDL_OPENGLES                (Wanted: ON): ON
--   SDL_OPENVR                  (Wanted: OFF): OFF
--   SDL_OSS                     (Wanted: OFF): OFF
--   SDL_PIPEWIRE                (Wanted: OFF): OFF
--   SDL_PIPEWIRE_SHARED         (Wanted: OFF): OFF
--   SDL_PTHREADS                (Wanted: OFF): OFF
--   SDL_PTHREADS_SEM            (Wanted: OFF): OFF
--   SDL_PULSEAUDIO              (Wanted: OFF): OFF
--   SDL_PULSEAUDIO_SHARED       (Wanted: OFF): OFF
--   SDL_RENDER_D3D              (Wanted: ON): ON
--   SDL_RENDER_D3D11            (Wanted: ON): ON
--   SDL_RENDER_D3D12            (Wanted: ON): ON
--   SDL_RENDER_GPU              (Wanted: ON): ON
--   SDL_RENDER_METAL            (Wanted: ON): OFF
--   SDL_RENDER_VULKAN           (Wanted: ON): ON
--   SDL_ROCKCHIP                (Wanted: OFF): OFF
--   SDL_RPATH                   (Wanted: OFF): OFF
--   SDL_RPI                     (Wanted: OFF): OFF
--   SDL_SNDIO                   (Wanted: OFF): OFF
--   SDL_SNDIO_SHARED            (Wanted: OFF): OFF
--   SDL_SSE                     (Wanted: ON): ON
--   SDL_SSE2                    (Wanted: ON): ON
--   SDL_SSE3                    (Wanted: ON): ON
--   SDL_SSE4_1                  (Wanted: ON): ON
--   SDL_SSE4_2                  (Wanted: ON): ON
--   SDL_SYSTEM_ICONV            (Wanted: OFF): OFF
--   SDL_TESTS                   (Wanted: OFF): OFF
--   SDL_TESTS_LINK_SHARED       (Wanted: OFF): OFF
--   SDL_UNINSTALL               (Wanted: OFF): OFF
--   SDL_VIRTUAL_JOYSTICK        (Wanted: ON): ON
--   SDL_VIVANTE                 (Wanted: OFF): OFF
--   SDL_VULKAN                  (Wanted: ON): ON
--   SDL_WASAPI                  (Wanted: ON): ON
--   SDL_WAYLAND                 (Wanted: OFF): OFF
--   SDL_WAYLAND_LIBDECOR        (Wanted: OFF): OFF
--   SDL_WAYLAND_LIBDECOR_SHARED (Wanted: OFF): OFF
--   SDL_WAYLAND_SHARED          (Wanted: OFF): OFF
--   SDL_X11                     (Wanted: OFF): OFF
--   SDL_X11_SHARED              (Wanted: OFF): OFF
--   SDL_X11_XCURSOR             (Wanted: OFF): OFF
--   SDL_X11_XDBE                (Wanted: OFF): OFF
--   SDL_X11_XFIXES              (Wanted: OFF): OFF
--   SDL_X11_XINPUT              (Wanted: OFF): OFF
--   SDL_X11_XRANDR              (Wanted: OFF): OFF
--   SDL_X11_XSCRNSAVER          (Wanted: OFF): OFF
--   SDL_X11_XSHAPE              (Wanted: OFF): OFF
--   SDL_X11_XSYNC               (Wanted: OFF): OFF
--   SDL_X11_XTEST               (Wanted: OFF): OFF
--   SDL_XINPUT                  (Wanted: ON): ON
--
--  Build Shared Library: OFF
--  Build Static Library: ON
--
-- Using the multi-header code from C:/Users/[Redacted]/Desktop/Genesis/External/Json/include/
-- Configuring done (0.9s)
-- Generating done (0.5s)
-- Build files have been written to: C:/Users/[Redacted]/Desktop/Genesis/Build
[Genesis Build] Building Genesis Game...
MSBuild version 17.14.10+8b8e13593 for .NET Framework

  Checking File Globs
  SDL_uclibc.vcxproj -> C:\Users\[Redacted]\Desktop\Genesis\Build\lib\Release\SDL_uclibc.lib
  SDL3-static.vcxproj -> C:\Users\[Redacted]\Desktop\Genesis\Build\lib\Release\SDL3-static.lib
  GenesisEngine.vcxproj -> C:\Users\[Redacted]\Desktop\Genesis\Build\lib\Release\GenesisEngine.lib
  GenesisGame.vcxproj -> C:\Users\[Redacted]\Desktop\Genesis\Build\bin\Release\GenesisGame.exe
  SDL3_test.vcxproj -> C:\Users\[Redacted]\Desktop\Genesis\Build\lib\Release\SDL3_test.lib
[Genesis Build] Build complete. Launching game...
SDL_Init Error:

C:\Users\[Redacted]\Desktop\Genesis>

```
