#pragma once

#include <string>
#include "Engine/Core/IWindow.h"

namespace Meteor {
    class Window : IWindow {
        public:
            virtual void* GetNativeWindow() override;
            virtual int GetWidth() override;
            virtual int GetHeight() override;
            virtual void SetEventCallback(const EventCallback& eventCallback) override;
            Window(const std::string& title, const int width, const int height);
            ~Window();  
        private:
            GLFWwindow* m_NativeWindow;
            std::string m_Title;
            int m_Width;
            int m_Height;
            EventCallback m_EventCallback;

            void Initialize();
            void Shutdown();
    };
}