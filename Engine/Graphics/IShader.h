#pragma once

namespace Meteor {
    class IShader {
        public:
            virtual void Use() = 0;
    };
}