#pragma once
#include <string>
#include <vector>

namespace Utils {
    class FileUtils {
    public:
        static std::vector<char> readFile(const std::string& filename);
    };
}
