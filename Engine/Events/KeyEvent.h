#pragma once

#include "Events/IEvent.h"

namespace Meteor {
    class KeyEvent : public IEvent {
        public:
            virtual EventType GetType() const override { return m_EventType; };
            virtual std::string GetName() const override { return m_EventName; };
            virtual std::any GetData() const override { return GetKeyCode(); };
            int GetKeyCode() const { return m_KeyCode; }
            
            KeyEvent(const EventType eventType, const std::string eventName, const int keyCode)
                : m_EventType(eventType), m_EventName(eventName), m_KeyCode(keyCode) {}
            ~KeyEvent() {}

        private:
            EventType m_EventType;
            std::string m_EventName;
            int m_KeyCode;
    };
}