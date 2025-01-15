#include "Core/IWindow.h"
#include "Core/Window.h"

namespace Meteor {
    std::shared_ptr<IWindow> IWindow::Create(const WindowProperties& properties) {
        std::string title = properties.m_Title;
        int width = properties.m_Width;
        int height = properties.m_Height;

        return std::make_shared<IWindow>(new Window(title, width, height));
    }
}