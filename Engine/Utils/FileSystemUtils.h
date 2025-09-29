#pragma once

#include <filesystem>

#if defined(_WIN32)
  #define NOMINMAX
  #include <windows.h>
#elif defined(__APPLE__)
  #include <mach-o/dyld.h>
  #include <limits.h>
  #include <unistd.h>
#elif defined(__linux__)
  #include <unistd.h>
  #include <limits.h>
#endif

namespace Meteor {
    class FileSystemUtils {
        public:
            static std::filesystem::path GetExecutablePath();
    };
}