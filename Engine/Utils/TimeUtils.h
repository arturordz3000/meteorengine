#pragma once

#include <string>
#include <ctime>

namespace Meteor {
    class TimeUtils
    {
        public:
            static std::string GetFormattedCurrentTime(const std::string& format = "%Y-%m-%d %H:%M:%S");
    };
}