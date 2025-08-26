#include "TriangleScene.h"

namespace Meteor {
    std::string TriangleScene::GetName() const {
        return "TriangleScene";
    }

    void TriangleScene::OnInitialize() {
        Logger::GetInstance().Info("TriangleScene: OnInitialize()");
    }

    void TriangleScene::OnFinalize() {
        Logger::GetInstance().Info("TriangleScene: OnFinalize()");
    }

    void TriangleScene::OnUpdate(float deltaTime) {
        Logger::GetInstance().Info("TriangleScene: OnUpdate()");
    }

    void TriangleScene::OnEvent(const AbstractEvent& event) {
        Logger::GetInstance().Info("TriangleScene: OnEvent()");
    }
}