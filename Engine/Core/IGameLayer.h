#pragma once

#include <string>
#include "Events/AbstractEvent.h"

namespace Meteor {
    class IGameLayer {
        public:
            virtual std::string& GetName() const = 0;
            virtual void OnInitialize() = 0;
            virtual void OnFinalize() = 0;
            virtual void OnUpdate(float deltaTime) = 0;
            virtual void OnEvent(const AbstractEvent& event) = 0;
    };
}