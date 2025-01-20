#include <any>
#include <GLFW/glfw3.h>
#include "Core/Application.h"
#include "Events/KeyReleasedEvent.h"

namespace Meteor {
    Application* Application::s_Instance = nullptr;

    Application::Application() {
        m_IsRunning = true;
        m_Window = IWindow::Create();

        std::function<void(AbstractEvent&)> boundOnEvent = std::bind(&Application::OnEvent, this, std::placeholders::_1);
        m_Window->SetEventCallback(boundOnEvent);

        s_Instance = this;
    }

    Application::~Application() {
        Close();
    }

    void Application::Run() {
        while (IsRunning()) {
            m_Window->OnUpdate();
        }
    }

    void Application::OnEvent(const AbstractEvent& event) {
        switch (event.GetType()) {
            case EventType::KeyReleased:
                handleKeyEvent(event);
                break;

            case EventType::WindowClosed:
                handleWindowClosedEvent(event);
                break;
            
            default:
                break;
        }
    }

    void Application::handleKeyEvent(const AbstractEvent& event) {
        int keyCode = std::any_cast<int>(event.GetData());

        if (keyCode == GLFW_KEY_ESCAPE) {
            Close();
        }
    }

    void Application::handleWindowClosedEvent(const AbstractEvent& event) {
        GLFWwindow* window = std::any_cast<GLFWwindow*>(event.GetData());

        if (window == m_Window->GetNativeWindow()) {
            Close();
        }
    }

    void Application::Close() {
        m_IsRunning = false;
    }

    IWindow& Application::GetWindow() const {
        return *m_Window;
    }
}