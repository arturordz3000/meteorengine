#pragma once

#include <string>
#include <any>

namespace Meteor {
    enum EventType {
        KeyPressed,
        KeyReleased
    };

    class IEvent {
        public:
            virtual EventType GetType() const = 0;
            virtual std::string GetName() const = 0;
            virtual std::any GetData() const = 0;
    };
}