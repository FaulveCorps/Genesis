#pragma once

namespace Engine {

    void Init();
    void Run();
    void Shutdown();
    void InitPhysics();        
    void UpdatePhysics(float deltaTime); 
    void ShutdownPhysics();

    bool InitRenderer(SDL_Window* sdlWindow);  // Called from Engine::Init
    void BeginFrame();                         // bgfx::touch(), bgfx::frame()
    void EndFrame();
    void ShutdownRenderer();
}
