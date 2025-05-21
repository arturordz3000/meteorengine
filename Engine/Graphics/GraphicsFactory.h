#pragma once

#include "Graphics/IContext.h"
#include "Graphics/AbstractRenderer.h"
#include "Core/IWindow.h"

namespace Meteor {
    class GraphicsFactory {
        public:
            static std::shared_ptr<IContext> CreateContext(IWindow& window);
            static std::shared_ptr<AbstractRenderer> CreateRenderer(IWindow& window);
    };
}