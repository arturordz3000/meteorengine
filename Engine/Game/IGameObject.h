#pragma once

namespace Meteor {
    class IGameObject {
        public:
            virtual void Update(float deltaTime) = 0;
    };
}