#pragma once

#include <functional>
#include "Events/Event.h"

namespace Meteor {
    using EventCallback = std::function<void(Event&)>;
}