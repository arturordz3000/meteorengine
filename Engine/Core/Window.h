#pragma once

#include <string>
#include <GLFW/glfw3.h>
#include "Core/IWindow.h"

namespace Meteor {
    class Window : public IWindow {
        public:
            virtual void* GetNativeWindow() const override;
            virtual std::string GetTitle() const override;
            virtual int GetWidth() const override;
            virtual int GetHeight() const override;
            virtual void SetEventCallback(const EventCallback& eventCallback) override;
            virtual void OnUpdate() override;
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