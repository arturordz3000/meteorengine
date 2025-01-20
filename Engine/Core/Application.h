#pragma once

#include <memory>
#include <unordered_map>
#include "Events/AbstractEvent.h"
#include "Core/IWindow.h"
#include "Core/IApplicationLayer.h"

namespace Meteor {
    class Application {
        public:
            Application();
            virtual ~Application();

            static Application& Get() { return *s_Instance; }
            bool IsRunning() const { return m_IsRunning; }
            void Run();
            void OnEvent(const AbstractEvent& event);
            void Close();
            IWindow& GetWindow() const;
            
            u_int16_t AddApplicationLayer(IApplicationLayer* layer);
            bool RemoveApplicationLayer(const u_int16_t layerId);

        private:
            static Application* s_Instance;
            static u_int16_t s_NextLayerId;

            std::shared_ptr<IWindow> m_Window;
            bool m_IsRunning;
            std::unordered_map<u_int16_t, IApplicationLayer*> m_ApplicationLayers;

            void handleKeyEvent(const AbstractEvent& event);
            void handleWindowClosedEvent(const AbstractEvent& event);
    };
}