#include "Graphics/GraphicsFactory.h"
#include "Graphics/OpenGlContext.h"
#include "Graphics/OpenGlRenderer.h"

namespace Meteor {
    std::shared_ptr<IContext> GraphicsFactory::CreateContext(IWindow& window) {
        auto openGlContext = std::make_shared<OpenGlContext>(window);
        return openGlContext;
    }

    std::shared_ptr<AbstractRenderer> GraphicsFactory::CreateRenderer(IWindow& window) {
        auto openGlRenderer = std::make_shared<OpenGlRenderer>(window);
        openGlRenderer->Initialize();
        return openGlRenderer;
    }
}