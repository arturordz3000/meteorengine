#pragma once

#include "Events/AbstractEvent.h"

namespace Meteor {
    class KeyEvent : public AbstractEvent {
        public:
            virtual std::any GetData() const override { return GetKeyCode(); };
            int GetKeyCode() const { return m_KeyCode; }
            
            KeyEvent(const EventType eventType, const std::string eventName, const int keyCode)
                : AbstractEvent(eventType, eventName), m_KeyCode(keyCode) {}
            ~KeyEvent() {}

        private:
            int m_KeyCode;
    };
}