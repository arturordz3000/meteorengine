#pragma once

#include "IFile.h"
#include "Logger/Logger.h"
#include "Utils/FileSystemUtils.h"

#include <fstream>
#include <sstream>
#include <cerrno>
#include <cstring>

namespace Meteor {
    const std::filesystem::path BASE_DIR = FileSystemUtils::GetExecutablePath();

    class File : public IFile {
        public:
            File(const std::string& filePath);
            ~File() {
                Close();
            }

            virtual void Close() override;

            virtual std::string GetContent() const override;
        
        private:
            std::ifstream file;
    };
}