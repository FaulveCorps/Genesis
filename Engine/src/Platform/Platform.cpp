#include "Genesis/Platform/Platform.h"

#include <SDL3/SDL.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>


static SDL_Window* window = nullptr;
static bool shouldClose = false;

static Genesis::Platform::WindowDesc currentDesc;

Genesis::Platform::WindowDesc Init(const Genesis::Platform::WindowDesc& settings) {
    currentDesc = settings;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return currentDesc;
    }

    Uint32 flags = SDL_WINDOW_RESIZABLE;

    window = SDL_CreateWindow(settings.title, settings.width, settings.height, flags);

    if (!window) {
        SDL_Log("Failed to create SDL window: %s", SDL_GetError());
        return currentDesc;
    }

    // Setup bgfx platform data
    bgfx::PlatformData pd{};
    pd.nwh = window;
    pd.ndt = nullptr;
    bgfx::setPlatformData(pd);


    bgfx::Init bgfxInit{};
    bgfxInit.type = bgfx::RendererType::Count;
    bgfxInit.resolution.width = settings.width;
    bgfxInit.resolution.height = settings.height;
    bgfxInit.resolution.reset = settings.vsync ? BGFX_RESET_VSYNC : BGFX_RESET_NONE;
    bgfxInit.platformData = pd;

    if (!bgfx::init(bgfxInit)) {
        SDL_Log("Failed to initialize bgfx.");
        SDL_DestroyWindow(window);
        SDL_Quit();
        return currentDesc;
    }

    return currentDesc;
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
