#include "TriangleScene.h"

namespace Meteor {
    std::string TriangleScene::GetName() const {
        return "TriangleScene";
    }

    void TriangleScene::OnInitialize() {

    }

    void TriangleScene::OnFinalize() {
        Logger::GetInstance().Info("TriangleScene: OnFinalize()");
    }

    void TriangleScene::OnUpdate(float deltaTime) {
        this->renderer->Render(triangle);
    }

    void TriangleScene::OnEvent(const AbstractEvent& event) {
        Logger::GetInstance().Info("TriangleScene: OnEvent()");
    }
}