#include <iostream>
#include <mutex>
#include <memory>
#include <ctime>
#include <sstream>
#include <thread>
#include "Logger/ILogger.h"

namespace Meteor {
    class ConsoleLogger : public ILogger {
        public:
            virtual void Debug(std::string message) override;
            virtual void Error(std::string message) override;
            virtual void Warning(std::string message) override;
            virtual void Info(std::string message) override;

        private:
            void Log(const std::string& level, std::string message);
            std::mutex m_Mutex;      
    };
}