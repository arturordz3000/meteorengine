#pragma once

#include "glm/gtc/matrix_transform.hpp"
#include "Graphics/ICamera.h"

namespace Meteor {
    class PerspectiveCamera : public ICamera {
        public:
            PerspectiveCamera(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up, float aspectRatio);

            virtual glm::mat4 GetViewMatrix() const override;
            virtual glm::mat4 GetProjectionMatrix() const override;
            void SetPerspective(float fieldOfView, float nearPlane, float farPlane);
        private:
            void updateCameraVectors();

            glm::vec3 m_Position;
            glm::vec3 m_Target;
            glm::vec3 m_Up;
            glm::vec3 m_InitialFront;
            glm::vec3 m_Front;
            glm::vec3 m_Right;

            float m_Yaw;
            float m_Pitch;

            float m_AspectRatio;
            float m_FieldOfView;
            float m_NearPlane;
            float m_FarPlane;
    };
}