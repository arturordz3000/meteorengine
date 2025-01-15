#pragma once

#include "Events/IEvent.h"
#include "Events/KeyEvent.h"

namespace Meteor {
    class KeyReleasedEvent : public KeyEvent {
        public:
            KeyReleasedEvent(const int keyCode)
                : KeyEvent(EventType::KeyReleased, "KeyReleasedEvent", keyCode) {}
    };
}