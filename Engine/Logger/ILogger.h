#pragma once

#include <string>

namespace Meteor {
    class ILogger {
        public:
            virtual void Debug(std::string message) = 0;
            virtual void Error(std::string message) = 0;
            virtual void Warning(std::string message) = 0;
            virtual void Info(std::string message) = 0;
    };
}