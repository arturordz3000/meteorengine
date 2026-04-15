#pragma once

#define GL_GLEXT_PROTOTYPES

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Graphics/AbstractRenderable.h"
#include "Graphics/OpenGlShaderCompiler.h"
#include "Logger/Logger.h"
#include "Game/IGameObject.h"

namespace Meteor {
    class Rectangle : public AbstractRenderable, IGameObject {
        private:
            std::vector<float> vertices;
            std::vector<unsigned int> indices;
            unsigned int vertexBufferObject;
            unsigned int vertexArrayObject;
            unsigned int elementBufferObject;
        public:
            Rectangle() { Initialize(); };
            void Initialize();
            virtual void Update(float deltaTime) override;
            virtual void Render() override;
    };   
}