#pragma once

#include "Events/Event.h"
#include "Core/IWindow.h"

namespace Meteor {
    class Application {
        public:
            Application();
            virtual ~Application();

            static Application& Get() { return *s_Instance; }
            void OnEvent(const Event& event);
            void Close();
            IWindow& GetWindow();

        private:
            static Application* s_Instance;
    };
}