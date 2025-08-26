#include "CubeScene.h"

namespace Meteor {
    std::string CubeScene::GetName() const {
        return "CubeScene";
    }

    void CubeScene::OnInitialize() {
        Logger::GetInstance().Info("CubeScene: OnInitialize()");
    }

    void CubeScene::OnFinalize() {
        Logger::GetInstance().Info("CubeScene: OnFinalize()");
    }

    void CubeScene::OnUpdate(float deltaTime) {
        Logger::GetInstance().Info("CubeScene: OnUpdate()");
    }

    void CubeScene::OnEvent(const AbstractEvent& event) {
        Logger::GetInstance().Info("CubeScene: OnEvent()");
    }
}