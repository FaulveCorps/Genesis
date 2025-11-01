#include <SDL3/SDL.h>
#include <iostream>

void EngineInit() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL Init failed: " << SDL_GetError() << "\n";
        return;
    }

    SDL_Window* window = SDL_CreateWindow("Genesis Game Engine", 1280, 720, SDL_WINDOW_RESIZABLE);
    SDL_ShowWindow(window);
    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << "\n";
        SDL_Quit();
        return;
    }

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL Init failed: " << SDL_GetError() << "\n";
        return;
    }


    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) running = false;
        }
        SDL_Delay(16);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}
