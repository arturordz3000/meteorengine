#pragma once

#include "ICamera.h"

namespace Meteor {
    struct PerspectiveCameraParams {
        glm::vec3 position{0.0f};
        glm::vec3 lookAt{0.0f, 0.0f, -1.0f};
        glm::vec3 up{0.0f, 1.0f, 0.0f};
        float fov = 45.0f;
        float aspect = 16.0f / 9.0f;
        float near = 0.1f;
        float far = 100.0f;
    };

    class PerspectiveCamera : public ICamera {
        public:
            explicit PerspectiveCamera(PerspectiveCameraParams& params) :
                m_Position(params.position),
                m_LookAt(params.lookAt),
                m_Up(params.up),
                m_Fov(glm::radians(params.fov)),
                m_Aspect(params.aspect),
                m_Near(params.near),
                m_Far(params.far) {
                    Initialize();
                }

            void SetPosition(float x, float y, float z);
            void SetLookAt(float x, float y, float z);
            void SetUp(float x, float y, float z);
            void SetFov(float fov);
            void SetAspect(float aspect);
            void SetNear(float near);
            void SetFar(float far);
            const glm::vec3& GetPosition() const;
            const glm::vec3& GetLookAt() const;
            const glm::vec3& GetUp() const;
            float GetFov() const;
            float GetAspect() const;
            float GetNear() const;
            float GetFar() const;
            virtual const glm::mat4& GetViewMatrix() const override;
            virtual const glm::mat4& GetProjectionMatrix() const override;
            virtual const glm::mat4& GetViewProjectionMatrix() const override;
        private:
            glm::vec3 m_Position;
            glm::vec3 m_LookAt;
            glm::vec3 m_Up;
            float m_Fov;
            float m_Aspect;
            float m_Near;
            float m_Far;

            // Mutable is to override the const rule
            mutable bool m_ViewDirty { true };
            mutable bool m_ProjectionDirty { true };
            mutable bool m_ViewProjectionDirty { true };

            mutable glm::mat4 m_ViewMatrix;
            mutable glm::mat4 m_ProjectionMatrix;
            mutable glm::mat4 m_ViewProjectionMatrix;

            void Initialize();
            void RebuildViewMatrix();
            void RebuildProjectionMatrix();
            void RebuildViewProjectionMatrix();
    };
}