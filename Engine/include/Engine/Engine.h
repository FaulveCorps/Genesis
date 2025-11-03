#pragma once
#include <SDL3/SDL.h>

namespace Genesis {
    bool Init(const char* title, uint16_t width, uint16_t height);
    void BeginFrame();
    void EndFrame();
    void Shutdown();
}
