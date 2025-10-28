#include "PerspectiveCamera.h"

namespace Meteor {
    void PerspectiveCamera::Initialize() {
        RebuildViewMatrix();
        RebuildProjectionMatrix();
    }

    void PerspectiveCamera::SetPosition(float x, float y, float z) {
        m_Position = glm::vec3(x, y, z);
        RebuildViewMatrix();
    }

    void PerspectiveCamera::SetLookAt(float x, float y, float z) {
        m_LookAt = glm::vec3(x, y, z);
        RebuildViewMatrix();
    }

    void PerspectiveCamera::SetUp(float x, float y, float z) {
        m_Up = glm::vec3(x, y ,z);
    }

    void PerspectiveCamera::SetFov(float fov) {
        m_Fov = glm::radians(fov);
    }

    void PerspectiveCamera::SetAspect(float aspect) {
        m_Aspect = aspect;
    }

    void PerspectiveCamera::SetNear(float near) {
        m_Near = near;
    }

    void PerspectiveCamera::SetFar(float far) {
        m_Far = far;
    }

    const glm::vec3& PerspectiveCamera::GetPosition() const {
        return m_Position;
    }

    const glm::vec3& PerspectiveCamera::GetLookAt() const {
        return m_LookAt;
    }

    const glm::vec3& PerspectiveCamera::GetUp() const {
        return m_Up;
    }

    float PerspectiveCamera::GetFov() const {
        return m_Fov;
    }

    float PerspectiveCamera::GetAspect() const {
        return m_Aspect;
    }

    float PerspectiveCamera::GetNear() const {
        return m_Near;
    }

    float PerspectiveCamera::GetFar() const {
        return m_Far;
    }

    const glm::mat4& PerspectiveCamera::GetViewMatrix() const {
        return m_ViewMatrix;
    }

    const glm::mat4& PerspectiveCamera::GetProjectionMatrix() const {
        return m_ProjectionMatrix;
    }

    void PerspectiveCamera::RebuildViewMatrix() {
        m_ViewMatrix = glm::lookAt(m_Position, m_LookAt, m_Up);
    }

    void PerspectiveCamera::RebuildProjectionMatrix() {
        m_ProjectionMatrix = glm::perspective(m_Fov, m_Aspect, m_Near, m_Far);
    }
}