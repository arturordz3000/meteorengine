#pragma once

#include "Core/IWindow.h"

namespace Meteor {
    class IContext {
        public:
            virtual void* GetNativeWindow() const = 0;
            virtual IWindow& GetWindow() const = 0;
            virtual void SwapBuffers() = 0;
    };
}