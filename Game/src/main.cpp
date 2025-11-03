// Game/main.cpp
#include <Engine/Engine.h>

int main()
{
    if (!Genesis::Init("Genesis Game Engine", 1280, 720))
        return -1;

    bool running = true;
    while (running)
    {
        Genesis::BeginFrame();
        Genesis::EndFrame();
    }

    Genesis::Shutdown();
    return 0;
}
