#include "Logger/Logger.h"
#include "Logger/ConsoleLogger.h"

namespace Meteor {
    ILogger& Logger::GetInstance() {
        static ConsoleLogger logger;
        return logger;
    }
}