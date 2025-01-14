#pragma once

#include "Engine/Events/IEvent.h"
#include "Engine/Events/KeyEvent.h"

namespace Meteor {
    class KeyReleasedEvent : public KeyEvent {
        public:
            KeyReleasedEvent(const int keyCode)
                : KeyEvent(EventType::KeyReleased, "KeyReleasedEvent", keyCode) {}
    };
}