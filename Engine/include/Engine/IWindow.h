#pragma once

namespace Engine {

    class IWindow {
    public:
        virtual ~IWindow() = default;

        virtual bool Init(const char* title, int width, int height) = 0;
        virtual void PollEvents() = 0;
        virtual void Shutdown() = 0;
        virtual bool IsRunning() const = 0;
    };

}
