#include <GLFW/glfw3.h>
#include "Graphics/OpenGlContext.h"

namespace Meteor {
    void OpenGlContext::Initialize() {
        m_NativeWindow = (GLFWwindow*)GetWindow().GetNativeWindow();
        glfwMakeContextCurrent(m_NativeWindow);
    }

    IWindow& OpenGlContext::GetWindow() const {
        return m_Window;
    }

    void OpenGlContext::SwapBuffers() {
        glfwSwapBuffers(m_NativeWindow);
    }
}