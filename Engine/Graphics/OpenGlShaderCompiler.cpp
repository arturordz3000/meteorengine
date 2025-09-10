#include "OpenGlShaderCompiler.h"

namespace Meteor {
    std::unique_ptr<IShader> OpenGlShaderCompiler::CompileFromSource(const std::string& vertexShaderSource, const std::string& fragmentShaderSource) {
        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        const char *vs = vertexShaderSource.c_str();
        glShaderSource(vertexShader, 1, &vs, NULL);
        glCompileShader(vertexShader);

        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        const char *fs = vertexShaderSource.c_str();
        glShaderSource(fragmentShader, 1, &fs, NULL);
        glCompileShader(fragmentShader);

        unsigned int shaderProgram;
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        return std::make_unique<OpenGlShader>(shaderProgram);
    }

    std::unique_ptr<IShader> OpenGlShaderCompiler::CompileFromFile(const std::string& vertexShaderFile, const std::string& fragmentShaderFile) {
        return NULL;
    }
}