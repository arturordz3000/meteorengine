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

    void OpenGlRenderer::StartScene(ICamera& camera) {

    }

    void OpenGlRenderer::EndScene() {

    }

    void OpenGlRenderer::Render(AbstractRenderable& renderable) {
        renderable.Render();
    }
}