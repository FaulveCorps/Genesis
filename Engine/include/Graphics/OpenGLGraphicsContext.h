// Engine/include/Graphics/OpenGLGraphicsContext.h
#pragma once

#include "Graphics/IGraphicsContext.h"
#include <SDL3/SDL.h>

namespace Engine {

class OpenGLGraphicsContext : public IGraphicsContext {
public:
    OpenGLGraphicsContext(SDL_Window* window);
    ~OpenGLGraphicsContext();

    bool Init(void* window_handle) override;
    void OnResize(int width, int height) override;
    void Clear(float r, float g, float b, float a) override;
    void Present() override;

private:
    SDL_Window* m_Window;
    SDL_GLContext m_GLContext;
    bool m_Initialized = false;
};

} // namespace Engine
