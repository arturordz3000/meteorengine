#pragma once

#include "Engine/Events/IEvent.h"
#include "Engine/Events/KeyEvent.h"

namespace Meteor {
    class KeyPressedEvent : public KeyEvent {
        public:
            KeyPressedEvent(const int keyCode)
                : KeyEvent(EventType::KeyPressed, "KeyPressedEvent", keyCode) {}
    };
}