#pragma once

#include "Core/IWindow.h"

namespace Meteor {
    class IContext {
        public:
            virtual IWindow& GetWindow() const = 0;
            virtual void SwapBuffers() = 0;
    };
}