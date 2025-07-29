#include "Genesis/Core/Engine.h"

int main() {
    Genesis::Engine::Init();

    while (!Genesis::Engine::ShouldQuit()) {
        Genesis::Engine::Tick();
    }

    Genesis::Engine::Shutdown();
    return 0;
}