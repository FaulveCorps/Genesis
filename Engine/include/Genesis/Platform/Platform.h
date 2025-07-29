#pragma once

struct WindowDesc {
    const char* title;
    int width, height;
    bool resizable;
};

namespace Genesis::Platform {
    void Init(const WindowDesc& desc);
    void PollEvents();
    bool ShouldClose();
    void Shutdown();
    void* GetNativeWindowHandle();
}
