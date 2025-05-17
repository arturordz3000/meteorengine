#pragma once

#include "Graphics/IContext.h"
#include "Core/IWindow.h"

namespace Meteor {
    class Context {
        public:
            static std::shared_ptr<IContext> CreateOpenGlContext(IWindow& window);
    };
}