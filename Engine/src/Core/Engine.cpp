#include "Genesis/Core/Engine.h"
#include "Genesis/Platform/Platform.h"
#include "Genesis/Renderer/Renderer.h"
#include "Genesis/Debug/Log.h"
#include "Game/Game.h"

#include <bgfx/bgfx.h>


static bool running = true;

void Genesis::Engine::Init() {
    LOG_INFO("[Engine] Initializing...");

    auto desc = Platform::Init(
        {
            "Genesis Engine", 
            1280, 
            720, 
            true, 
            true
        }
    );

    bgfx::Init init;
    init.type = bgfx::RendererType::Count;
    init.resolution.width = desc.width;
    init.resolution.height = desc.height;
    init.resolution.reset = BGFX_RESET_VSYNC;
    bgfx::init(init);

    Renderer::Init();
    Game::Init();
}


void Genesis::Engine::Tick() {
    Platform::PollEvents();
    if (Platform::ShouldClose()) running = false;

    Renderer::BeginFrame();
    Game::Update(0.016f);  // Example delta time
    Game::Render();
    Renderer::EndFrame();
}

void Genesis::Engine::Shutdown() {
    Game::Shutdown();
    Renderer::Shutdown();
    Platform::Shutdown();
    LOG_INFO("[Engine] Shutdown complete.");
}

bool Genesis::Engine::ShouldQuit() {
    return !running;
}
