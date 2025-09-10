#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Events/WindowEvent.h"

namespace Meteor {
    class WindowClosedEvent : public WindowEvent {
        public:
            WindowClosedEvent(GLFWwindow* window)
                : WindowEvent(EventType::WindowClosed, "WindowClosedEvent", window) {}
    };
}