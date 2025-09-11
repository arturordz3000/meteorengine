#pragma once

#include "glm/gtc/matrix_transform.hpp"
#include "Graphics/IContext.h"
#include "Graphics/ICamera.h"
#include "Graphics/AbstractRenderable.h"

namespace Meteor {
    class AbstractRenderer {
        public:
            void virtual Initialize() = 0;
            void virtual Render(AbstractRenderable &renderable) = 0;
            void virtual StartScene() = 0;
            void virtual EndScene() = 0;
        protected:
            int m_Width, m_Height;
            glm::mat4 m_ProjectionMatrix;
    };
}