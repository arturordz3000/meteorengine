#pragma once

#include <string>

namespace Meteor {
    struct Texture {
        unsigned int textureId;
        std::string type;
        std::string path;
    };
}