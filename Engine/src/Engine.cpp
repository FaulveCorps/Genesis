#include "Engine/Engine.h"
#include "Engine/SDLWindow.h"

#include <memory>
#include <iostream>

namespace Engine {

    std::unique_ptr<Engine::SDLWindow> window;

    void Init() {
        std::cout << "[Engine] Initialization..." << std::endl;
        window = std::make_unique<SDLWindow>();
        if (!window->Init("Genesis Engine", 800, 600)) {
            std::cerr << "[Engine] Window failed to initialize!" << std::endl;
            exit(1);
        }
    }

    void Run() {
        std::cout << "[Engine] Running..." << std::endl;
        while (window->IsRunning()) {
            window->PollEvents();
        }
    }

    void Shutdown() {
        window->Shutdown();
        std::cout << "[Engine] Shutdown complete." << std::endl;
    }

}
