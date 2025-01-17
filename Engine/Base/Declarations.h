#pragma once

#include <functional>
#include "Events/AbstractEvent.h"

namespace Meteor {
    using EventCallback = std::function<void(AbstractEvent&)>;
}