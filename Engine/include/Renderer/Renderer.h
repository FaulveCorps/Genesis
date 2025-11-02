#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <iostream>
namespace Genesis {
    class Renderer {
    public:
        void Init(void* windowHandle, uint16_t width, uint16_t height);
        void Frame();
        void Shutdown();
    };
}
