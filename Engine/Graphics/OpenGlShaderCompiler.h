#pragma once

#include <memory>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "IShader.h"
#include "OpenGlShader.h"

namespace Meteor {
    class OpenGlShaderCompiler {
        public:
            static std::unique_ptr<IShader> CompileFromSource(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
            static std::unique_ptr<IShader> CompileFromFile(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
    };
}