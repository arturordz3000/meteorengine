#pragma once

#include "glm/gtc/matrix_transform.hpp"

namespace Meteor {
    class ICamera {
        public:
            virtual glm::mat4 GetViewMatrix() const = 0;
            virtual glm::mat4 GetProjectionMatrix() const = 0;
    };
}