#include "Genesis/Platform/Platform.h"
#include <SDL3/SDL.h>

static SDL_Window* window = nullptr;
static bool shouldClose = false;

void Genesis::Platform::Init(const WindowDesc& desc) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(desc.title, desc.width, desc.height, SDL_WINDOW_RESIZABLE);
}

void Genesis::Platform::PollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT)
            shouldClose = true;
    }
}

bool Genesis::Platform::ShouldClose() {
    return shouldClose;
}

void Genesis::Platform::Shutdown() {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void* Genesis::Platform::GetNativeWindowHandle() {
    return (void*)SDL_GetWindowWMInfo(window); // Needed by bgfx
}
