#include "TriangleScene.h"

namespace Meteor {
    std::string TriangleScene::GetName() const {
        return "TriangleScene";
    }

    void TriangleScene::OnInitialize() {
        this->triangle = std::make_unique<Triangle>();
    }

    void TriangleScene::OnFinalize() {
        Logger::GetInstance().Info("TriangleScene: OnFinalize()");
    }

    void TriangleScene::OnUpdate(float deltaTime) {
        this->renderer->StartScene();
        this->renderer->Render(*triangle);
        this->renderer->EndScene();
    }

    void TriangleScene::OnEvent(const AbstractEvent& event) {
        Logger::GetInstance().Info("TriangleScene: OnEvent()");
    }
}