#pragma once

#include <functional>
#include "Engine/Events/Event.h"

namespace Meteor {
    using EventCallback = std::function<void(Event&)>;
}