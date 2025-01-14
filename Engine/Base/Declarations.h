#pragma once

#include <functional>
#include "Engine/Events/IEvent.h"

namespace Meteor {
    using EventCallback = std::function<void(IEvent&)>;
}