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
    class Triangle : public AbstractRenderable, IGameObject {
        private:
            std::vector<float> vertices;
            unsigned int vertexBufferObject;
            unsigned int vertexArrayObject;
        public:
            Triangle() { Initialize(); };
            void Initialize();
            virtual void Update(float deltaTime) override;
            virtual void Render() override;
    };   
}