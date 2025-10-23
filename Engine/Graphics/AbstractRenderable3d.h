#pragma once

#include "Graphics/AbstractRenderable.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

namespace Meteor {
    class AbstractRenderable3d : public AbstractRenderable {
        public:
            AbstractRenderable3d() :
                m_ModelMatrix(glm::mat4(1.0f)),
                m_RotationMatrix(glm::mat4(1.0f)),
                m_Scale(glm::vec3(1.0f,1.0f,1.0f)),
                m_Translation(glm::vec3(0, 0, 0)) { }

            const glm::mat4& GetModelMatrix() const;
            void SetRotation(float yaw, float pitch, float roll);
            void SetScale(float x, float y, float z);
            void SetTranslation(float x, float y, float z);
        
        protected:
            glm::mat4 m_ModelMatrix;
            glm::mat4 m_RotationMatrix;
            glm::vec3 m_Scale;
            glm::vec3 m_Translation;

        private:
            void RebuildModelMatrix();
    };
}