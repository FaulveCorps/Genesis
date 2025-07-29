#include "Genesis/Core/Engine.h"
#include "Genesis/Platform/Platform.h"
#include "Genesis/Renderer/Renderer.h"
#include "Genesis/Debug/Log.h"
#include "Game/Game.h"

static bool running = true;

void Genesis::Engine::Init() {
    LOG_INFO("[Engine] Initializing...");
    Platform::Init({"Genesis Engine", 1280, 720, true});
    Renderer::Init();
    Game::Init();
}

void Genesis::Engine::Tick() {
    Platform::PollEvents();
    if (Platform::ShouldClose()) running = false;

    Renderer::BeginFrame();
    Game::Update(0.016f);  // Dummy delta
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
