#pragma once

#include <string>
#include <glm/glm.hpp>
#include "Graphics/Texture.h"

namespace Meteor {
    enum ShaderType {
        VertextShader,
        FragmentShader
    };

    class IShader {
        public:
            virtual void AttachShader(const std::string& filePath, ShaderType shaderType) = 0;
            virtual void Link() = 0;
            virtual void Use() = 0;
            virtual void SetUniform(const std::string& name, const glm::mat4& matrix) const = 0;
            virtual void SetUniform(const std::string& name, const glm::vec3& vector) const = 0;
            virtual void SetUniform(const std::string& name, const float value) const = 0;
            virtual void SetUniform(const std::string& name, const int value) const = 0;
            virtual void BindTexture(const Texture& texture) const = 0;
    };
}