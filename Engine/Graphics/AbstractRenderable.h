#pragma once

#include "Graphics/IShader.h"

namespace Meteor {
    class AbstractRenderable {
        public:
            virtual void Render() = 0;
            void SetShader(IShader& shader) { this->shader = shader; }
        private:
            IShader& shader;
    };
}