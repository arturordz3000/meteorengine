#pragma once

#include "glm/gtc/matrix_transform.hpp"
#include "Graphics/IContext.h"
#include "Graphics/ICamera.h"

namespace Meteor {
    class AbstractRenderer {
        public:
            void virtual Initialize(IContext& context) = 0;
            void virtual Render() = 0;
            void virtual ResizeViewport(int width, int height) = 0;
            void virtual StartScene(ICamera& camera) = 0;
            void virtual EndScene() = 0;
        private:
            int m_Width, m_Height;
            glm::mat4 m_ProjectionMatrix;
    };
}