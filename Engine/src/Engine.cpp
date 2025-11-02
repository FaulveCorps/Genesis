#include "Engine.h"
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

void SetupBgfx(SDL_Window* window)
{
    bgfx::PlatformData pd{};
    SDL_PropertiesID props = SDL_GetWindowProperties(window);

#if defined(_WIN32)
    pd.nwh = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_WIN32_HWND_POINTER, nullptr);
#elif defined(__linux__)
    pd.ndt = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_X11_DISPLAY_POINTER, nullptr);
    pd.nwh = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_X11_WINDOW_NUMBER, nullptr);
#elif defined(__APPLE__)
    pd.nwh = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_COCOA_WINDOW_POINTER, nullptr);
#endif

    pd.context = nullptr;
    pd.backBuffer = nullptr;
    pd.backBufferDS = nullptr;

    bgfx::setPlatformData(pd);

    bgfx::Init init;
    init.type = bgfx::RendererType::Count;
    init.resolution.width = 1280;
    init.resolution.height = 720;
    init.resolution.reset = BGFX_RESET_VSYNC;
    bgfx::init(init);
}

void EngineInit(SDL_Window** outWindow)
{
    SDL_Init(SDL_INIT_VIDEO);
    *outWindow = SDL_CreateWindow("Genesis Game Engine", 1280, 720, SDL_WINDOW_RESIZABLE);
    SetupBgfx(*outWindow);
}
