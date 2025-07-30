#pragma once

namespace Genesis::Time {

    void Init();
    void Tick(); // Call once per frame

    float GetDeltaTime();    // Time between frames
    float GetTotalTime();    // Time since engine start

}
