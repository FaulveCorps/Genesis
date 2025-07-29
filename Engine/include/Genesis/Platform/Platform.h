#pragma once

namespace Genesis::Platform {

    struct WindowDesc {
        const char* title = "Genesis Engine";
        int width = 1280;
        int height = 720;
        bool resizable = true;
        bool vsync = true;
    };

    WindowDesc Init(const WindowDesc& settings);

    void* CreateWindow(const WindowDesc& desc);
    void* GetNativeWindowHandle();
    void ShutdownWindow();

    void PollEvents();
    bool ShouldClose();
    void Shutdown();
    void* GetNativeWindowHandle();
}
