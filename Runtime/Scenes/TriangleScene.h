#pragma once

#include "Logger/Logger.h"
#include "Game/AbstractScene.h"
#include "../Actors/Triangle.h"

namespace Meteor {
    class TriangleScene : public AbstractScene {
        private:
            std::shared_ptr<Triangle> triangle;

        public:
            TriangleScene() { }
            ~TriangleScene() { }
            virtual std::string GetName() const override;
            virtual void OnInitialize() override;
            virtual void OnFinalize() override;
            virtual void OnUpdate(float deltaTime) override;
            virtual void OnEvent(const AbstractEvent& event) override;
    };
}