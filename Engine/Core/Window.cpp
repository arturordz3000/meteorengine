#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cassert>
#include <iostream>
#include "Core/Window.h"
#include "Events/KeyPressedEvent.h"
#include "Events/KeyReleasedEvent.h"
#include "Events/WindowClosedEvent.h"

namespace Meteor {
    unsigned int s_WindowCount = 0;

    Window::Window(const std::string& title, const int width, const int height) {
        m_Title = title;
        m_Width = width;
        m_Height = height;

        Initialize();
    }

    Window::~Window() {
        Shutdown();
    }

    void* Window::GetNativeWindow() const {
        return m_NativeWindow;
    }

    std::string Window::GetTitle() const {
        return m_Title;
    }

    int Window::GetWidth() const {
        return m_Width;
    }

    int Window::GetHeight() const {
        return m_Height;
    }

    void Window::SetEventCallback(const EventCallback& event) {
        m_EventCallback = event;
    }

    void Window::Initialize() {
        if (s_WindowCount == 0) {
            assert(glfwInit() && "Failed to initialize GLFW");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_NativeWindow = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);

        if (!m_NativeWindow) {
            std::cerr << "Window with ID " << s_WindowCount + 1 << " could not be initialized";
            return;
        }

        s_WindowCount++;

        glfwMakeContextCurrent(m_NativeWindow);
        glViewport(0, 0, m_Width, m_Height);

        glfwSetFramebufferSizeCallback(m_NativeWindow, [](GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);
        });

        glfwSetWindowUserPointer(m_NativeWindow, &m_EventCallback);

        glfwSetKeyCallback(m_NativeWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			EventCallback& eventCallback = *(EventCallback*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key);
					eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					eventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key);
					eventCallback(event);
					break;
				}
			}
		});

        glfwSetWindowCloseCallback(m_NativeWindow, [](GLFWwindow* window) {
            EventCallback& eventCallback = *(EventCallback*)glfwGetWindowUserPointer(window);

            WindowClosedEvent event(window);
            eventCallback(event);
        });
    }

    void Window::OnUpdate() {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(m_NativeWindow);
        glfwPollEvents();
    }

    void Window::Shutdown() {
        glfwDestroyWindow(m_NativeWindow);
        s_WindowCount--;

        if (s_WindowCount == 0) {
            glfwTerminate();
        }
    }
}