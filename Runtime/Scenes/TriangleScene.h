#pragma once

#include "Logger/Logger.h"
#include "Game/AbstractScene.h"
#include "../Actors/Triangle.h"

namespace Meteor {
    class TriangleScene : public AbstractScene {
        private:
            Triangle triangle;

        public:
            TriangleScene() { OnInitialize(); }
            ~TriangleScene() { OnFinalize(); }
            virtual std::string GetName() const override;
            virtual void OnInitialize() override;
            virtual void OnFinalize() override;
            virtual void OnUpdate(float deltaTime) override;
            virtual void OnEvent(const AbstractEvent& event) override;
    };
}