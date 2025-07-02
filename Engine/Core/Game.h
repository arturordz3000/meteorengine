#pragma once

#include <memory>
#include <unordered_map>
#include "Events/AbstractEvent.h"
#include "Core/IWindow.h"
#include "Core/IGameLayer.h"

namespace Meteor {
    class Game {
        public:
            Game();
            virtual ~Game();

            static Game& Get() { return *s_Instance; }
            bool IsRunning() const { return m_IsRunning; }
            void Run();
            void OnEvent(const AbstractEvent& event);
            void Close();
            IWindow& GetWindow() const;
            
            u_int16_t AddLayer(IGameLayer* layer);
            bool RemoveLayer(const u_int16_t layerId);

        private:
            static Game* s_Instance;
            static u_int16_t s_NextLayerId;

            std::shared_ptr<IWindow> m_Window;
            bool m_IsRunning;
            std::unordered_map<u_int16_t, IGameLayer*> m_GameLayers;

            void handleKeyEvent(const AbstractEvent& event);
            void handleWindowClosedEvent(const AbstractEvent& event);
    };
}