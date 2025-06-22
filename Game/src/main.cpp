#include "Engine/SDLWindow.h"

int main() {
    Engine::SDLWindow window;

    // Example: manually override to fullscreen with OpenGL
    SDL_WindowFlags customFlags = (SDL_WindowFlags)(SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);

    if (!window.Init("Genesis", 1280, 720, customFlags)) {
        return -1;
    }

    while (window.IsRunning()) {
        window.PollEvents();
        // Render / Update here
    }

    window.Shutdown();
    return 0;
}
