#pragma once

#include "Logger/Logger.h"
#include "Game/AbstractScene.h"
#include "../Actors/Triangle.h"
#include "../Actors/Rectangle.h"

namespace Meteor {
    class TestScene : public AbstractScene {
        private:
            std::shared_ptr<Triangle> triangle;
            std::shared_ptr<Rectangle> rectangle;

        public:
            TestScene() { }
            ~TestScene() { }
            virtual std::string GetName() const override;
            virtual void OnInitialize() override;
            virtual void OnFinalize() override;
            virtual void OnUpdate(float deltaTime) override;
            virtual void OnEvent(const AbstractEvent& event) override;
    };
}