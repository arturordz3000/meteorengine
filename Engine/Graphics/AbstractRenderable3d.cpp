#include "Graphics/AbstractRenderable3d.h"

namespace Meteor {
    void AbstractRenderable3d::SetRotation(float yaw, float pitch, float roll) {
        // @TODO: Convert to quaternions later on
        this->m_RotationMatrix = glm::yawPitchRoll(glm::radians(yaw), glm::radians(pitch), glm::radians(roll));
        this->RecomputeModelMatrix();
    }

    void AbstractRenderable3d::SetScale(float x, float y, float z) {
        this->m_Scale = glm::vec3(x, y, z);
        this->RecomputeModelMatrix();
    }

    void AbstractRenderable3d::SetTranslation(float x, float y, float z) {
        this->m_Translation = glm::vec3(x, y, z);
        this->RecomputeModelMatrix();
    }

    const glm::mat4& AbstractRenderable3d::GetModelMatrix() const {
        return this->m_ModelMatrix;
    }

    void AbstractRenderable3d::RecomputeModelMatrix() {
        // The Model matrix is: model = Translation * Rotation * Scale
        this->m_ModelMatrix = glm::translate(glm::mat4(1.0f), this->m_Translation);
        this->m_ModelMatrix *= this->m_RotationMatrix;
        this->m_ModelMatrix = glm::scale(this->m_ModelMatrix, this->m_Scale);
    }
}