#include "TestScene.h"

namespace Meteor {
    std::string TestScene::GetName() const {
        return "TestScene";
    }

    void TestScene::OnInitialize() {
        this->triangle = std::make_shared<Triangle>();
        this->rectangle = std::make_shared<Rectangle>();
    }

    void TestScene::OnFinalize() {
        Logger::GetInstance().Info(GetName() + ": OnFinalize()");
    }

    void TestScene::OnUpdate(float deltaTime) {
        this->renderer->StartScene();
        this->renderer->Render(*triangle);
        this->renderer->Render(*rectangle);
        this->renderer->EndScene();
    }

    void TestScene::OnEvent(const AbstractEvent& event) {
        Logger::GetInstance().Info(GetName() + ": OnEvent()");
    }
}