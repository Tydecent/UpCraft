#pragma once

#include <string>
#include <vector>
#include <windows.h>
#include <filesystem>
namespace fs = std::filesystem;


namespace UpCraft {
    namespace utils {
        std::string get_current_exe_path();
    }
}