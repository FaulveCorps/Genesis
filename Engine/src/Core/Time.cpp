#include "Genesis/Core/Time.h"
#include <chrono>

namespace Genesis::Time {

    static std::chrono::steady_clock::time_point startTime;
    static std::chrono::steady_clock::time_point lastFrameTime;
    static float deltaTime = 0.0f;

    void Init() {
        startTime = std::chrono::steady_clock::now();
        lastFrameTime = startTime;
    }

    void Tick() {
        auto currentTime = std::chrono::steady_clock::now();
        deltaTime = std::chrono::duration<float>(currentTime - lastFrameTime).count();
        lastFrameTime = currentTime;
    }

    float GetDeltaTime() {
        return deltaTime;
    }

    float GetTotalTime() {
        return std::chrono::duration<float>(std::chrono::steady_clock::now() - startTime).count();
    }

}
