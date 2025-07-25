// Engine/include/Graphics/IGraphicsContext.h
#pragma once

namespace Engine {

class IGraphicsContext {
public:
    virtual ~IGraphicsContext() = default;

    // Initialize the graphics context (create device, swapchain, etc)
    virtual bool Init(void* window_handle) = 0;

    // Resize the viewport or swapchain buffers on window resize
    virtual void OnResize(int width, int height) = 0;

    // Clear the screen (with a color)
    virtual void Clear(float r, float g, float b, float a) = 0;

    // Present the backbuffer (swap buffers)
    virtual void Present() = 0;
};

} // namespace Engine
