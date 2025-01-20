#include "Logger/ConsoleLogger.h"
#include "Utils/TimeUtils.h"

namespace Meteor {
    void ConsoleLogger::Debug(std::string message) {
        Log("DEBUG", message);
    }

    void ConsoleLogger::Error(std::string message) {
        Log("ERROR", message);
    }

    void ConsoleLogger::Warning(std::string message) {
        Log("WARNING", message);
    }

    void ConsoleLogger::Info(std::string message) {
        Log("INFO", message);
    }

    void ConsoleLogger::Log(const std::string& level, std::string message) {
        std::lock_guard<std::mutex> lock(m_Mutex);

        std::ostringstream logMessage;

        logMessage << "[" << TimeUtils::GetFormattedCurrentTime() << "] "
                   << "[" << level << "] "
                   << "[Thread " << std::this_thread::get_id() << "] "
                   << message << "\n";

        const std::string& logStr = logMessage.str();

        std::cout << logStr;
    }
}