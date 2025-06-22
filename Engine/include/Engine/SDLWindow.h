#pragma once
#include <SDL3/SDL.h>

namespace Engine {

    class SDLWindow {
    public:
        SDLWindow();
        ~SDLWindow();

        bool Init(const char* title, int width, int height, SDL_WindowFlags flags = 0);
        void PollEvents();
        bool IsRunning() const;
        void Shutdown();

    private:
        SDL_Window* m_Window = nullptr;
        bool m_Running = false;

        SDL_WindowFlags AutoDetectFlags(); // Internal detection logic
    };

}
