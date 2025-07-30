#include "Genesis/Core/Application.h"
#include "Genesis/Platform/Platform.h"
#include "Genesis/Renderer/Renderer.h"
#include "Genesis/Debug/Log.h"
#include "Game/Game.h"
#include "Genesis/Core/Time.h"

#include <bgfx/bgfx.h>

namespace Genesis {

    Application::Application() = default;

    Application::~Application() = default;

    void Application::Init() {
        LOG_INFO("[Application] Initializing...");

        // Initialize Time
        Time::Init();

        auto desc = Platform::Init({
            "Genesis Engine",
            1280, 720,
            true, true
        });

        Renderer::Init();
        Game::Init();
    }

    void Application::Run() {
        Init();

        while (m_Running && !Platform::ShouldClose()) {
            Time::Tick();  // Update time for deltaTime

            Platform::PollEvents();
            Renderer::BeginFrame();
            
            // Pass deltaTime to game update
            Game::Update(Time::GetDeltaTime());
            Game::Render();
            
            Renderer::EndFrame();
        }

        Shutdown();
    }

    void Application::Shutdown() {
        Game::Shutdown();
        Renderer::Shutdown();
        Platform::Shutdown();
        LOG_INFO("[Application] Shutdown complete.");
    }

}
