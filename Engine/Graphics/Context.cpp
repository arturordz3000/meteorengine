#include "Graphics/Context.h"
#include "Graphics/OpenGlContext.h"

namespace Meteor {
    std::shared_ptr<IContext> Context::CreateOpenGlContext(IWindow& window) {
        auto openGlContext = std::make_shared<OpenGlContext>(window);
        return openGlContext;
    }
}