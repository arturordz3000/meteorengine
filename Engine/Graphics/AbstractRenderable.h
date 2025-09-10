#pragma once

#include <memory>
#include "Graphics/IShader.h"

namespace Meteor {
    class AbstractRenderable {
        public:
            virtual void Render() = 0;
            void SetShader(std::unique_ptr<IShader> shader) { this->shader = std::move(shader); }
        protected:
            std::unique_ptr<IShader> shader;
    };
}