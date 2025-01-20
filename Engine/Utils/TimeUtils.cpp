#include "Utils/TimeUtils.h"

namespace Meteor {
    std::string TimeUtils::GetFormattedCurrentTime(const std::string& format) {
        std::time_t now = std::time(nullptr);
        char buf[100];
        std::strftime(buf, sizeof(buf), format.c_str(), std::localtime(&now));
        return std::string(buf);
    }
}