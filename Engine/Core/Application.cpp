#include <any>
#include <GLFW/glfw3.h>
#include "Core/Application.h"
#include "Events/KeyReleasedEvent.h"
#include "Logger/Logger.h"

namespace Meteor {
    Application* Application::s_Instance = nullptr;
    u_int16_t Application::s_NextLayerId = 0;

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
        Logger::GetInstance().Info("Starting application...");
        
        while (IsRunning()) {
            m_Window->OnUpdate();

            for (auto& [layerId, layer] : m_ApplicationLayers) {
                layer->OnUpdate(0);
            }
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

        for (auto& [layerId, layer] : m_ApplicationLayers) {
            layer->OnEvent(event);
        }
    }

    u_int16_t Application::AddApplicationLayer(IApplicationLayer* layer) {
        m_ApplicationLayers[++s_NextLayerId] = layer;
        layer->OnInitialize();

        return s_NextLayerId;
    }

    bool Application::RemoveApplicationLayer(const u_int16_t layerId) {
        if (m_ApplicationLayers.count(layerId) == 0) {
            return false;
        }

        IApplicationLayer* layer = m_ApplicationLayers[layerId];
        layer->OnFinalize();
        delete layer;

        return true;
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