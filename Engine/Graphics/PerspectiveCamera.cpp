#include "Graphics/PerspectiveCamera.h"

namespace Meteor {
    PerspectiveCamera::PerspectiveCamera(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up, float aspectRatio) {
        m_Position = position;
        m_Target = target;
        m_Up = up;
        m_AspectRatio = aspectRatio;

        m_InitialFront = glm::normalize(target - position);

        updateCameraVectors();
    }

    void PerspectiveCamera::updateCameraVectors() {
        float yawAsRadians = glm::radians(m_Yaw);
        float pitchAsRadians = glm::radians(m_Pitch);

        glm::vec3 rotatedFront;
        rotatedFront.x = glm::cos(pitchAsRadians) * glm::cos(yawAsRadians);
        rotatedFront.y = glm::sin(pitchAsRadians);
        rotatedFront.z = glm::cos(pitchAsRadians) * glm::sin(yawAsRadians);

        m_Front = glm::normalize(m_InitialFront + rotatedFront);
        m_Right = glm::normalize(glm::cross(m_Front, m_Up));
        m_Up = glm::normalize(glm::cross(m_Front, m_Right));
    }
}