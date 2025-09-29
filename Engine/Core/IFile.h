#pragma once

#include <string>

namespace Meteor {
    class IFile {
        public:
            virtual void Close() = 0;
            virtual std::string GetContent() const = 0;
    };
}