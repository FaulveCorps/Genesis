#include <SDL3/SDL.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <iostream>

void EngineInit() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n";
        return;
    }

    SDL_Window* window = SDL_CreateWindow("Genesis Game Engine", 1280, 720, SDL_WINDOW_RESIZABLE);

    // SDL3: get native window handle directly
    void* nativeHandle = SDL_CreateWindow("Genesis Game Engine",
        1280, 720,
        SDL_WINDOW_RESIZABLE);

    bgfx::PlatformData pd{};
#if defined(_WIN32)
    pd.nwh = nativeHandle; // HWND
#endif

    bgfx::Init init;
    init.type = bgfx::RendererType::Count; // auto-select renderer
    init.resolution.width = 1280;
    init.resolution.height = 720;
    init.resolution.reset = BGFX_RESET_VSYNC;
    init.platformData = pd;

    if (!bgfx::init(init)) {
        std::cerr << "bgfx init failed\n";
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    bool running = true;
    SDL_Event e;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) running = false;
        }

        bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x1E1E1EFF, 1.0f, 0);
        bgfx::setViewRect(0, 0, 0, 1280, 720);
        bgfx::touch(0);
        bgfx::frame();

        SDL_Delay(16);
    }

    bgfx::shutdown();
    SDL_DestroyWindow(window);
    SDL_Quit();
}
