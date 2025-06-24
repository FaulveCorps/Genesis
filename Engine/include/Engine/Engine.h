#pragma once

namespace Engine {

    void Init();
    void Run();
    void Shutdown();
    void InitPhysics();        
    void UpdatePhysics(float deltaTime); 
    void ShutdownPhysics();
}
