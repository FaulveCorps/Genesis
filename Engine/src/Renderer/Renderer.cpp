#include "Renderer/Renderer.h"
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <iostream>

using namespace Genesis;

static bool s_initialized = false;

void Genesis::Renderer::Init(void* windowHandle, uint16_t width, uint16_t height) {
    bgfx::PlatformData pd{};
    pd.nwh = windowHandle;
    pd.context = nullptr;
    pd.backBuffer = nullptr;
    pd.backBufferDS = nullptr;

    bgfx::Init init;
    init.type = bgfx::RendererType::Count;
    init.resolution.width = width;
    init.resolution.height = height;
    init.resolution.reset = BGFX_RESET_VSYNC;
    init.platformData = pd;

    bgfx::init(init);
    s_initialized = true;
}



void Renderer::Frame() {
    if (!s_initialized) return;

    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x1E1E1EFF, 1.0f, 0);
    bgfx::setViewRect(0, 0, 0, 1280, 720);
    bgfx::touch(0);
    bgfx::frame();
}

void Renderer::Shutdown() {
    if (!s_initialized) return;
    bgfx::shutdown();
    s_initialized = false;
}
