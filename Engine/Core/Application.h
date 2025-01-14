#pragma once

#include "Engine/Events/IEvent.h"
#include "Engine/Core/IWindow.h"

namespace Meteor {
    class Application {
        public:
            Application();
            virtual ~Application();

            static Application& Get() { return *s_Instance; }
            void OnEvent(const IEvent& event) const;
            void Close();
            IWindow& GetWindow() const;

        private:
            static Application* s_Instance;
    };
}