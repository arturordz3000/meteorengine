#pragma once

#include <memory>
#include "Engine/Events/IEvent.h"
#include "Engine/Core/IWindow.h"

namespace Meteor {
    class Application {
        public:
            Application();
            virtual ~Application();

            static Application& Get() { return *s_Instance; }
            bool IsRunning() { return m_IsRunning; }
            void OnEvent(const IEvent& event);
            void Close();
            IWindow& GetWindow() const;

        private:
            static Application* s_Instance;
            std::shared_ptr<IWindow> m_Window;
            bool m_IsRunning;
    };
}