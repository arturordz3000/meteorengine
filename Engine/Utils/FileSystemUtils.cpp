#include "FileSystemUtils.h"

namespace Meteor {
    std::filesystem::path FileSystemUtils::GetExecutablePath() {
        #if defined(_WIN32)
            // Handle paths longer than MAX_PATH by looping
            std::vector<wchar_t> buf(32768); // 32K should be plenty
            DWORD len = GetModuleFileNameW(nullptr, buf.data(), static_cast<DWORD>(buf.size()));
            if (len == 0 || len == buf.size()) throw std::runtime_error("GetModuleFileNameW failed");
            return std::filesystem::path(std::wstring(buf.data(), len)).parent_path();

        #elif defined(__APPLE__)
            uint32_t sz = 0;
            if (_NSGetExecutablePath(nullptr, &sz) != -1) {
                // Unexpected, but continue
            }
            std::vector<char> buf(sz);
            if (_NSGetExecutablePath(buf.data(), &sz) != 0) throw std::runtime_error("_NSGetExecutablePath failed");

            // Resolve symlinks to get a canonical path
            char resolved[PATH_MAX];
            if (realpath(buf.data(), resolved)) return std::filesystem::path(resolved);
            return std::filesystem::path(buf.data()).parent_path();

        #elif defined(__linux__)
            char buf[PATH_MAX];
            ssize_t n = readlink("/proc/self/exe", buf, sizeof(buf) - 1);
            if (n == -1) throw std::runtime_error("readlink(/proc/self/exe) failed");
            buf[n] = '\0';
            return std::filesystem::path(buf).parent_path();
        #endif
    }
}