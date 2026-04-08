#include <iostream>
#include <cassert>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Graphics/OpenGlContext.h"

void error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

namespace Meteor {
    void OpenGlContext::Initialize(IWindow& window) {
        if(!glfwInit()) {
            std::cerr << "Failed to initialize GLFW!" << std::endl;
            return;
        }

        glfwSetErrorCallback(error_callback);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        #ifdef __APPLE__
        // MacOS compatibility
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        int width = window.GetWidth();
        int height = window.GetHeight();
        std::string title = window.GetTitle();

        this->m_NativeWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

        if (!this->m_NativeWindow) {
            std::cerr << "Window could not be initialized" << std::endl;
            return;
        }

        glfwMakeContextCurrent(this->m_NativeWindow);

        GLenum err = glewInit();
        if (err != GLEW_OK) {
            std::cerr << "GLEW init failed: " << glewGetErrorString(err) << "\n";
            return;
        }

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