#pragma once

#include "Logger/ILogger.h"

namespace Meteor {
    class Logger {
        public:
            static ILogger& GetInstance();
    };
}