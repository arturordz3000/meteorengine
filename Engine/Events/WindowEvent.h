#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include "Events/AbstractEvent.h"

namespace Meteor {
    class WindowEvent : public AbstractEvent {
        public:
            WindowEvent(const EventType eventType, const std::string eventName, GLFWwindow* window) 
                : AbstractEvent(eventType, eventName), m_Window(window) {}

            virtual std::any GetData() const override { return m_Window; }

        private:
            GLFWwindow* m_Window;

    };
}