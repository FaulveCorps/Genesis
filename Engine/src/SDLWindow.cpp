#include <SDL3/SDL.h>
#include "Engine/SDLWindow.h"
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#endif

namespace Engine {

    SDLWindow::SDLWindow() = default;
    SDLWindow::~SDLWindow() { Shutdown(); }

    bool SDLWindow::Init(const char* title, int width, int height, SDL_WindowFlags flags) {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "[SDLWindow] SDL_Init failed: " << SDL_GetError() << "\n";
            return false;
        }

        if (flags == 0)
            flags = AutoDetectFlags();

        m_Window = SDL_CreateWindow(title, width, height, flags);
        if (!m_Window) {
            std::cerr << "[SDLWindow] Failed to create window: " << SDL_GetError() << "\n";
            return false;
        }

        m_Running = true;
        std::cout << "[SDLWindow] Window created.\n";
        return true;
    }

    void SDLWindow::PollEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT)
                m_Running = false;
        }
    }

    bool SDLWindow::IsRunning() const {
        return m_Running;
    }

    void SDLWindow::Shutdown() {
        if (m_Window) {
            SDL_DestroyWindow(m_Window);
            m_Window = nullptr;
        }
        SDL_Quit();
        std::cout << "[SDLWindow] Shutdown.\n";
    }

    SDL_WindowFlags SDLWindow::AutoDetectFlags() {
#if defined(__APPLE__)
        return SDL_WINDOW_METAL;
#elif defined(_WIN32)
        return SDL_WINDOW_OPENGL;
#elif defined(__linux__)
        return SDL_WINDOW_VULKAN;
#else
        return SDL_WINDOW_OPENGL;
#endif
    }

}
