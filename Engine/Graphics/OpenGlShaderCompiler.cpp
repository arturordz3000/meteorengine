#include "OpenGlShaderCompiler.h"

namespace Meteor {
    std::unique_ptr<IShader> OpenGlShaderCompiler::CompileFromSource(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) {
        Logger::GetInstance().Info("Compiling shaders...");
        
        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        const char *vs = vertexShaderSource.c_str();
        glShaderSource(vertexShader, 1, &vs, NULL);
        glCompileShader(vertexShader);

        int  success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            Logger::GetInstance().Error("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" + std::string(infoLog));
        }

        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        const char *fs = fragmentShaderSource.c_str();
        glShaderSource(fragmentShader, 1, &fs, NULL);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            Logger::GetInstance().Error("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" + std::string(infoLog));
        }

        unsigned int shaderProgram;
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if(!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            Logger::GetInstance().Error("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" + std::string(infoLog));
        }

        return std::make_unique<OpenGlShader>(shaderProgram);
    }

    std::unique_ptr<IShader> OpenGlShaderCompiler::CompileFromFile(const std::string& vertexShaderFile, const std::string& fragmentShaderFile) {
        return NULL;
    }
}