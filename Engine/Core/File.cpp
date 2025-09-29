#include "File.h"

namespace Meteor {
    File::File(const std::string& filePath)
        : file(BASE_DIR.string() + "/" + filePath) {
        if (!file.is_open()) {
            Logger::GetInstance().Error("Error loading file: " + BASE_DIR.string() + "/" + filePath + " (" + std::strerror(errno) + ")");
        }
    }

    void File::Close() {
        if (file.is_open()) {
            file.close();
        }
    }

    std::string File::GetContent() const {
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string content = buffer.str();

        return content;
    }
}