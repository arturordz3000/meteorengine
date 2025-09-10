#pragma once

#define GL_GLEXT_PROTOTYPES

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Graphics/AbstractRenderable.h"
#include "Graphics/OpenGlShaderCompiler.h"

namespace Meteor {
    class Triangle : public AbstractRenderable {
        private:
            std::vector<float> vertices; // 3x3 float array
            unsigned int vertexBufferObject;
            unsigned int vertexArrayObject;
        public:
            Triangle() { Initialize(); };
            void Initialize();
            virtual void Render() override;
    };   
}