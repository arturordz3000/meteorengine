#pragma once

#define GL_GLEXT_PROTOTYPES

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Graphics/AbstractRenderable.h"
#include "Graphics/OpenGlShaderCompiler.h"
#include "Logger/Logger.h"

namespace Meteor {
    class Rectangle : public AbstractRenderable {
        private:
            std::vector<float> vertices;
            std::vector<unsigned int> indices;
            unsigned int vertexBufferObject;
            unsigned int vertexArrayObject;
            unsigned int elementBufferObject;
        public:
            Rectangle() { Initialize(); };
            void Initialize();
            virtual void Render() override;
    };   
}