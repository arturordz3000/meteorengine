#include "Graphics/OpenGlShader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <Logger/Logger.h>

namespace Meteor {
    OpenGlShader::OpenGlShader() {
        m_ProgramId = glCreateProgram();
    }

    OpenGlShader::~OpenGlShader() {
        glDeleteProgram(m_ProgramId);
    }

    void OpenGlShader::AttachShader(const std::string& filePath, ShaderType shaderType) {
        std::string shaderSource = loadShaderSource(filePath);
        GLuint shaderId = compileShader(shaderSource, shaderType);

        glAttachShader(m_ProgramId, shaderId);
        glDeleteShader(shaderId);
    }

    void OpenGlShader::Link() {
        glLinkProgram(m_ProgramId);

        GLint success;
        glGetProgramiv(m_ProgramId, GL_LINK_STATUS, &success);

        if (!success) {
            char linkingLog[512];
            glGetProgramInfoLog(m_ProgramId, 512, nullptr, linkingLog);

            throw std::runtime_error("Shader compilation failed: " + std::string(linkingLog));
        }
    }

    void OpenGlShader::Use() {
        glUseProgram(m_ProgramId);
    }

    void OpenGlShader::SetUniform(const std::string& name, const glm::mat4& matrix) {
        glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
    }

    void OpenGlShader::SetUniform(const std::string& name, const glm::vec3& vector) {
        glUniform3fv(getUniformLocation(name), 1, &vector[0]);
    }  

    void OpenGlShader::SetUniform(const std::string& name, const float value) {
        glUniform1f(getUniformLocation(name), value);
    }

    void OpenGlShader::SetUniform(const std::string& name, const int value) {
        glUniform1i(getUniformLocation(name), value);
    }

    void OpenGlShader::BindTexture(const Texture& texture, int textureUnit) {
        glActiveTexture(GL_TEXTURE0 + textureUnit);
        SetUniform("material." + texture.type, textureUnit);
        glBindTexture(GL_TEXTURE_2D, texture.textureId);
        glActiveTexture(GL_TEXTURE0);
    }

    std::string OpenGlShader::loadShaderSource(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file " + filePath);
        }

        std::stringstream fileContentBuffer;
        fileContentBuffer << file.rdbuf();

        return fileContentBuffer.str();
    }

    GLuint OpenGlShader::compileShader(const std::string& source, ShaderType shaderType) {
        GLenum glShaderType = translateShaderTypeToOpenGlShader(shaderType);
        GLuint shaderId = glCreateShader(glShaderType);
        const char* sourcePointer = source.c_str();

        glShaderSource(shaderId, 1, &sourcePointer, nullptr);
        glCompileShader(shaderId);

        GLint success;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);

        if (!success) {
            char compilationLog[512];
            glGetShaderInfoLog(shaderId, 512, nullptr, compilationLog);

            throw std::runtime_error("Shader compilation failed: " + std::string(compilationLog));
        }

        return shaderId;
    }

    GLenum OpenGlShader::translateShaderTypeToOpenGlShader(ShaderType shaderType) {
        switch (shaderType)
        {
            case ShaderType::VertextShader:
                return GL_VERTEX_SHADER;
            case ShaderType::FragmentShader:
                return GL_FRAGMENT_SHADER;
        }
    }

    GLint OpenGlShader::getUniformLocation(const std::string& name) {
        if (m_UniformLocationCache.count(name) != 0) {
            return m_UniformLocationCache[name];
        }

        GLint location = glGetUniformLocation(m_ProgramId, name.c_str());
        if (location == -1) {
            Logger::GetInstance().Warning("Uniform " + name + " not found in shader program");
        }

        m_UniformLocationCache[name] = location;

        return location;
    }
}