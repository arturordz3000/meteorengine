#include <any>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cassert>
#include "Core/Game.h"
#include "Events/KeyReleasedEvent.h"
#include "Logger/Logger.h"

namespace Meteor {
    Game* Game::s_Instance = nullptr;
    u_int16_t Game::s_NextLayerId = 0;

    Game::Game() {
        assert(!s_Instance && "Game already exists");

        m_IsRunning = true;
        m_Window = IWindow::Create();

        std::function<void(AbstractEvent&)> boundOnEvent = std::bind(&Game::OnEvent, this, std::placeholders::_1);
        m_Window->SetEventCallback(boundOnEvent);

        s_Instance = this;
    }

    Game::~Game() {
        Close();
    }

    void Game::Run() {
        Logger::GetInstance().Info("Starting game...");
        
        while (IsRunning()) {
            m_Window->OnUpdate();

            for (auto& [layerId, layer] : m_GameLayers) {
                layer->OnUpdate(0);
            }
        }
    }

    void Game::OnEvent(const AbstractEvent& event) {
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

        for (auto& [layerId, layer] : m_GameLayers) {
            layer->OnEvent(event);
        }
    }

    u_int16_t Game::AddLayer(IGameLayer* layer) {
        m_GameLayers[++s_NextLayerId] = layer;
        layer->OnInitialize();

        return s_NextLayerId;
    }

    bool Game::RemoveLayer(const u_int16_t layerId) {
        if (m_GameLayers.count(layerId) == 0) {
            return false;
        }

        IGameLayer* layer = m_GameLayers[layerId];
        layer->OnFinalize();
        delete layer;

        return true;
    }

    void Game::handleKeyEvent(const AbstractEvent& event) {
        int keyCode = std::any_cast<int>(event.GetData());

        if (keyCode == GLFW_KEY_ESCAPE) {
            Close();
        }
    }

    void Game::handleWindowClosedEvent(const AbstractEvent& event) {
        GLFWwindow* window = std::any_cast<GLFWwindow*>(event.GetData());

        if (window == m_Window->GetNativeWindow()) {
            Close();
        }
    }

    void Game::Close() {
        m_IsRunning = false;
    }

    IWindow& Game::GetWindow() const {
        return *m_Window;
    }
}