#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Graphics/OpenGlRenderer.h"

namespace Meteor {
    void OpenGlRenderer::Initialize() {
        this->SetupOpenGl();
        this->SetupShaders();
    }

    void OpenGlRenderer::SetupOpenGl() {
        m_NativeWindow = (GLFWwindow*)this->m_Window.GetNativeWindow();
    }

    void OpenGlRenderer::SetupShaders() {

    }

    void OpenGlRenderer::StartScene() {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void OpenGlRenderer::EndScene() {
        glfwSwapBuffers(m_NativeWindow);
        glfwPollEvents();
    }

    void OpenGlRenderer::Render(AbstractRenderable& renderable) {
        renderable.Render();
    }
}