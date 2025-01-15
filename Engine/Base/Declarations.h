#pragma once

#include <functional>
#include "Events/IEvent.h"

namespace Meteor {
    using EventCallback = std::function<void(IEvent&)>;
}