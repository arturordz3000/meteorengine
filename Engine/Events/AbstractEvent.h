#pragma once

#include <string>
#include <any>

namespace Meteor {
    enum EventType {
        KeyPressed,
        KeyReleased,
        WindowClosed
    };

    class AbstractEvent {
        public:
            AbstractEvent(const EventType eventType, std::string eventName) 
                : m_EventType(eventType), m_EventName(eventName) {}

            virtual EventType GetType() const { return m_EventType; }
            virtual std::string GetName() const { return m_EventName; };
            virtual std::any GetData() const = 0;

        protected:
            EventType m_EventType;
            std::string m_EventName;
    };
}