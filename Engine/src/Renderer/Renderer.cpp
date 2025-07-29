#include "Genesis/Renderer/Renderer.h"
#include "Genesis/Platform/Platform.h"
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

void Genesis::Renderer::Init(GraphicsAPI api) {
    bgfx::Init init;
    init.platformData.nwh = Platform::GetNativeWindowHandle();
    init.type = bgfx::RendererType::Count; // Auto
    bgfx::init(init);
}

void Genesis::Renderer::BeginFrame() {
    bgfx::touch(0);
}

void Genesis::Renderer::EndFrame() {
    bgfx::frame();
}

void Genesis::Renderer::Shutdown() {
    bgfx::shutdown();
}