#include "Graphics/OpenGLGraphicsContext.h"
#include <SDL3/SDL.h>
#include <glad/gl.h>
#include <SDL3/SDL_opengl.h>

namespace Engine {

OpenGLGraphicsContext::OpenGLGraphicsContext(SDL_Window* window)
    : m_Window(window), m_GLContext(nullptr) {}

OpenGLGraphicsContext::~OpenGLGraphicsContext() {
    if (m_GLContext) {
        SDL_GL_DestroyContext(m_GLContext);
    }
}

bool OpenGLGraphicsContext::Init(void* window_handle) {
    if (!window_handle) return false;

    // Set OpenGL attributes BEFORE window creation if needed
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    m_GLContext = SDL_GL_CreateContext(static_cast<SDL_Window*>(window_handle));
    if (!m_GLContext) {
        SDL_Log("Failed to create OpenGL context: %s", SDL_GetError());
        return false;
    }

    // Load OpenGL functions using glad or your chosen loader
    if (gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress) == 0) {
        SDL_Log("Failed to initialize GLAD");
        return false;
    }

    SDL_Log("OpenGL Context Initialized: %s", glGetString(GL_VERSION));
    m_Initialized = true;
    return true;
}

void OpenGLGraphicsContext::OnResize(int width, int height) {
    glViewport(0, 0, width, height);
}

void OpenGLGraphicsContext::Clear(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLGraphicsContext::Present() {
    SDL_GL_SwapWindow(m_Window);
}

} // namespace Engine
