#pragma once

#include <memory>
#include "Events/AbstractEvent.h"
#include "Core/IWindow.h"

namespace Meteor {
    class Application {
        public:
            Application();
            virtual ~Application();

            static Application& Get() { return *s_Instance; }
            bool IsRunning() { return m_IsRunning; }
            void Run();
            void OnEvent(const AbstractEvent& event);
            void Close();
            IWindow& GetWindow() const;

        private:
            static Application* s_Instance;
            std::shared_ptr<IWindow> m_Window;
            bool m_IsRunning;

            void handleKeyEvent(const AbstractEvent& event);
            void handleWindowClosedEvent(const AbstractEvent& event);
    };
}