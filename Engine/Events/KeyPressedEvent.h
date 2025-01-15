#pragma once

#include "Events/IEvent.h"
#include "Events/KeyEvent.h"

namespace Meteor {
    class KeyPressedEvent : public KeyEvent {
        public:
            KeyPressedEvent(const int keyCode)
                : KeyEvent(EventType::KeyPressed, "KeyPressedEvent", keyCode) {}
    };
}