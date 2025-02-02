#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <unordered_map>
#include "Graphics/IShader.h"

namespace Meteor
{
    class OpenGlShader : public IShader
    {
        public:
            OpenGlShader();
            ~OpenGlShader();

            virtual void AttachShader(const std::string& filePath, ShaderType shaderType) override;
            virtual void Link() override;
            virtual void Use() override;
            virtual void SetUniform(const std::string& name, const glm::mat4& matrix) override;
            virtual void SetUniform(const std::string& name, const glm::vec3& vector) override;
            virtual void SetUniform(const std::string& name, const float value) override;
            virtual void SetUniform(const std::string& name, const int value) override;
            virtual void BindTexture(const Texture& texture, int textureUnit) override;

        private:
            GLuint m_ProgramId;
            std::unordered_map<std::string, GLint> m_UniformLocationCache;

            std::string loadShaderSource(const std::string& filePath);
            GLuint compileShader(const std::string& source, ShaderType shaderType);
            GLenum translateShaderTypeToOpenGlShader(ShaderType shaderType);
            GLint getUniformLocation(const std::string& name);
    };
}
