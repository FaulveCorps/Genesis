// main.cpp
#include "Engine/Engine.h"
#include "Engine/GameLayer.h"
#include <SDL3/SDL.h>

int main(int argc, char* argv[]) {
    if (!Engine::Initialize(argc, argv)) {
        return 1;
    }

    MyGameLayer game_layer;
    Engine::g_Engine->SetGameLayer(&game_layer);

    while (game_layer.IsRunning()) {
        Engine::g_Engine->GetInput().Update();
        SDL_Delay(10);
    }

    Engine::Shutdown();
    return 0;
}