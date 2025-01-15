#include <any>
#include <GLFW/glfw3.h>
#include "Core/Application.h"
#include "Events/KeyReleasedEvent.h"

namespace Meteor {
    Application* Application::s_Instance = nullptr;

    Application::Application() {
        m_IsRunning = true;
        m_Window = IWindow::Create();

        std::function<void(IEvent&)> boundOnEvent = std::bind(&Application::OnEvent, this, std::placeholders::_1);
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

    void Application::OnEvent(const IEvent& event) {
        int keyCode = std::any_cast<int>(event.GetData());

        switch (event.GetType()) {
            case EventType::KeyReleased:
                if (keyCode == GLFW_KEY_ESCAPE) {
                    Close();
                }

                break;
            
            default:
                break;
        }
    }

    void Application::Close() {
        m_IsRunning = false;
    }

    IWindow& Application::GetWindow() const {
        return *m_Window;
    }
}