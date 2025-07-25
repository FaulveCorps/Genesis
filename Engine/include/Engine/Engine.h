// Engine.h
#pragma once
#include <SDL3/SDL.h>
#include "Platform/SDLWindow.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <functional>
#include "Graphics/IGraphicsContext.h"

namespace Engine {

    class SDLWindow; 
    class GameLayer;

class Input {
public:
    using KeyCallback = std::function<void(SDL_Scancode, bool)>; // scancode, is_pressed
    using MouseButtonCallback = std::function<void(Uint32, bool)>; // button, is_pressed
    using MouseMotionCallback = std::function<void(int, int, int, int)>; // x, y, dx, dy
    using ActionCallback = std::function<void(const std::string&)>; // action name

    Input();
    void Update();
    bool IsKeyDown(SDL_Scancode scancode) const;
    bool IsKeyPressed(SDL_Scancode scancode) const;
    bool IsKeyReleased(SDL_Scancode scancode) const;
    bool IsMouseButtonDown(Uint32 button) const;
    bool IsMouseButtonPressed(Uint32 button) const;
    bool IsMouseButtonReleased(Uint32 button) const;
    void GetMousePosition(int& x, int& y) const;
    void GetMouseDelta(int& dx, int& dy) const;
    bool IsActionTriggered(const std::string& action) const;
    void LoadBindings(const std::string& config_file);

    // Register callbacks
    void RegisterKeyCallback(KeyCallback callback);
    void RegisterMouseButtonCallback(MouseButtonCallback callback);
    void RegisterMouseMotionCallback(MouseMotionCallback callback);
    void RegisterActionCallback(ActionCallback callback);

private:
    std::vector<bool> key_states;
    std::vector<bool> key_pressed;
    std::vector<bool> key_released;
    std::vector<bool> mouse_states;
    std::vector<bool> mouse_pressed;
    std::vector<bool> mouse_released;
    int mouse_x, mouse_y;
    int mouse_dx, mouse_dy;
    std::unordered_map<std::string, SDL_Scancode> action_bindings;
    std::vector<KeyCallback> key_callbacks;
    std::vector<MouseButtonCallback> mouse_button_callbacks;
    std::vector<MouseMotionCallback> mouse_motion_callbacks;
    std::vector<ActionCallback> action_callbacks;
};

// Abstract game layer interface
class GameLayer {
public:
    virtual ~GameLayer() = default;
    virtual void OnKeyEvent(SDL_Scancode scancode, bool is_pressed) = 0;
    virtual void OnMouseButtonEvent(Uint32 button, bool is_pressed) = 0;
    virtual void OnMouseMotionEvent(int x, int y, int dx, int dy) = 0;
    virtual void OnActionEvent(const std::string& action) = 0;
};

class Engine {
public:
    Engine();
    ~Engine();

    bool Init(int width, int height, const std::string& title, bool fullscreen = false);
    bool InitFromArgs(int argc, char* argv[]);
    void SetGameLayer(GameLayer* layer);
    Input& GetInput();

    IGraphicsContext* GetGraphicsContext() const { return m_GraphicsContext.get(); }
    

private:    
    std::unique_ptr<SDLWindow> m_Window;
    std::unique_ptr<IGraphicsContext> m_GraphicsContext;
    bool sdl_initialized;
    Input input;
    GameLayer* game_layer;
};


bool Initialize(int argc, char* argv[]);
void Shutdown();

extern Engine* g_Engine;

} // namespace Engine