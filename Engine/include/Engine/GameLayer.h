// GameLayer.h
#pragma once
#include "Engine/Engine.h"

class MyGameLayer : public Engine::GameLayer {
public:
    void OnKeyEvent(SDL_Scancode scancode, bool is_pressed) override;
    void OnMouseButtonEvent(Uint32 button, bool is_pressed) override;
    void OnMouseMotionEvent(int x, int y, int dx, int dy) override;
    void OnActionEvent(const std::string& action) override;
    bool IsRunning() const { return running; }

private:
    bool running = true;
};