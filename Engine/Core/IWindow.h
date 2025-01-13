#pragma once

#include <memory>
#include <string>
#include "Base/Declarations.h"

namespace Meteor {
    struct WindowProperties {
        int m_Width;
        int m_Height;
        std::string m_Title;

        WindowProperties(int width = 800, int height = 600, std::string title = "MeteorEngine")
            : m_Width(width), m_Height(height), m_Title(title) {}
    };

    class IWindow {
        public:
            static std::shared_ptr<IWindow> Create(const WindowProperties& properties = WindowProperties());
            virtual void* GetNativeWindow() = 0;
            virtual int GetWidth() = 0;
            virtual int GetHeight() = 0;
            virtual void SetEventCallback(const EventCallback& eventCallback) = 0;
    };
}