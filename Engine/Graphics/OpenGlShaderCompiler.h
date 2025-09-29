#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "IShader.h"
#include "OpenGlShader.h"
#include "Logger/Logger.h"
#include "Core/IFile.h"
#include "Core/File.h"

namespace Meteor {
    class OpenGlShaderCompiler {
        public:
            static std::unique_ptr<IShader> CompileFromSource(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
            static std::unique_ptr<IShader> CompileFromFile(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);
    };
}