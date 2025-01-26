#include "Graphics/Context.h"
#include "Graphics/OpenGlContext.h"

namespace Meteor {
    IContext& Context::CreateOpenGlContext(IWindow& window) {
        static OpenGlContext openGlContext(window);
        return openGlContext;
    }
}