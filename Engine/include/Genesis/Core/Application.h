#pragma once

namespace Genesis {

    class Application {
    public:
        Application();
        ~Application();

        void Run();

    private:
        bool m_Running = true;

        void Init();
        void Shutdown();
        void Tick();
    };

} // namespace Genesis
