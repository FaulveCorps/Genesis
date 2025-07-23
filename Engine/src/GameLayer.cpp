// GameLayer.cpp
#include "Engine/GameLayer.h"
#include "Engine/Log.h"

void MyGameLayer::OnKeyEvent(SDL_Scancode scancode, bool is_pressed) {
    if (is_pressed) {
        LOG_INFO("Key pressed: {}", SDL_GetScancodeName(scancode));
    } else {
        LOG_INFO("Key released: {}", SDL_GetScancodeName(scancode));
    }
}

void MyGameLayer::OnMouseButtonEvent(Uint32 button, bool is_pressed) {
    if (is_pressed) {
        LOG_INFO("Mouse button pressed: {}", button);
    } else {
        LOG_INFO("Mouse button released: {}", button);
    }
}

void MyGameLayer::OnMouseMotionEvent(int x, int y, int dx, int dy) {
    LOG_INFO("Mouse moved to ({}, {}), delta ({}, {})", x, y, dx, dy);
}

void MyGameLayer::OnActionEvent(const std::string& action) {
    LOG_INFO("Action triggered: {}", action);
    if (action == "quit") {
        running = false;
    }
}