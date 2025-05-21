#include <iostream>
#include <cassert>
#include <GLFW/glfw3.h>
#include "Graphics/OpenGlContext.h"

namespace Meteor {
    void OpenGlContext::Initialize(IWindow& window) {
        assert(glfwInit() && "Failed to initialize GLFW");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        int width = window.GetWidth();
        int height = window.GetHeight();
        std::string title = window.GetTitle();

        this->m_NativeWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

        if (!this->m_NativeWindow) {
            std::cerr << "Window could not be initialized";
            return;
        }

        glfwMakeContextCurrent(this->m_NativeWindow);
        glViewport(0, 0, width, height);

        glfwSetFramebufferSizeCallback(m_NativeWindow, [](GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);
        });
    }

    void* OpenGlContext::GetNativeWindow() const {
        return m_NativeWindow;
    }

    IWindow& OpenGlContext::GetWindow() const {
        return m_Window;
    }

    void OpenGlContext::SwapBuffers() {
        glfwSwapBuffers(m_NativeWindow);
    }
}