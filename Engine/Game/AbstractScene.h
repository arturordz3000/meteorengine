#pragma once

#include <memory>
#include "Core/IGameLayer.h"
#include "Graphics/AbstractRenderer.h"

namespace Meteor {
    class AbstractScene : public IGameLayer {
        public:
            void SetRenderer(std::shared_ptr<AbstractRenderer> renderer) { this->renderer = renderer; }
        protected:
            std::shared_ptr<AbstractRenderer> renderer;
    };
}