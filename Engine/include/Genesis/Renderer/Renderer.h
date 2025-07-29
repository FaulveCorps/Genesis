#pragma once

namespace Genesis::Renderer {
    enum class GraphicsAPI {
        Auto, OpenGL, Vulkan, Metal, Direct3D
    };

    void Init(GraphicsAPI api = GraphicsAPI::Auto);
    void BeginFrame();
    void EndFrame();
    void Shutdown();
}
