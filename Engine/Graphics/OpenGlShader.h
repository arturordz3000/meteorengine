#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "IShader.h"

namespace Meteor {
    class OpenGlShader : public IShader {
        public:
            OpenGlShader(unsigned int shaderProgram) { this->shaderProgram = shaderProgram; }
            ~OpenGlShader();
            virtual void Use() override;
        private:
            unsigned int shaderProgram;
    };
}