#include "Engine.h"
#include <SDL3/SDL.h>
#include <bgfx/bgfx.h>

int main()
{
    SDL_Window* window = nullptr;
    EngineInit(&window);

    bool running = true;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
                running = false;
        }

        bgfx::touch(0);
        bgfx::frame();
    }

    bgfx::shutdown();
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
