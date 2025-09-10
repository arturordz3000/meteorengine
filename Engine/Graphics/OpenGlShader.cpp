#include "OpenGlShader.h"

namespace Meteor {
    OpenGlShader::~OpenGlShader() {
        glDeleteShader(shaderProgram);
    }

    void OpenGlShader::Use() {
        glUseProgram(shaderProgram);
    }
}