#pragma once

#include "Graphics/IContext.h"
#include "Core/IWindow.h"

namespace Meteor {
    class Context {
        public:
            static IContext& CreateOpenGlContext(IWindow& window);
    };
}