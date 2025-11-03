#include "Engine/Engine.h"
#include "Renderer/Renderer.h"
#include <SDL3/SDL.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

using namespace Genesis;

static SDL_Window* s_window = nullptr;
static Renderer s_renderer;

bool Genesis::Init(const char* title, uint16_t width, uint16_t height)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return false;

    s_window = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);
    if (!s_window)
        return false;

    SDL_PropertiesID props = SDL_GetWindowProperties(s_window);
    bgfx::PlatformData pd{};

#if defined(_WIN32)
    pd.nwh = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_WIN32_HWND_POINTER, nullptr);
#elif defined(__linux__)
    pd.ndt = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_X11_DISPLAY_POINTER, nullptr);
    pd.nwh = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_X11_WINDOW_NUMBER, nullptr);
    if (!pd.nwh)
    {
        pd.ndt = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_WAYLAND_DISPLAY_POINTER, nullptr);
        pd.nwh = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_WAYLAND_SURFACE_POINTER, nullptr);
    }
#elif defined(__APPLE__)
    pd.nwh = SDL_GetPointerProperty(props, SDL_PROP_WINDOW_COCOA_WINDOW_POINTER, nullptr);
#endif

    pd.context = nullptr;
    pd.backBuffer = nullptr;
    pd.backBufferDS = nullptr;

    bgfx::setPlatformData(pd);

    s_renderer.Init(s_window, width, height);
    return true;
}

void Genesis::BeginFrame()
{
    bgfx::touch(0);
}

void Genesis::EndFrame()
{
    bgfx::frame();
}

void Genesis::Shutdown()
{
    s_renderer.Shutdown();
    SDL_DestroyWindow(s_window);
    SDL_Quit();
}
