#include "utils.h"

namespace UpCraft {
    namespace utils {
        std::string get_current_exe_path() {
            wchar_t exePath[MAX_PATH];
            GetModuleFileNameW(NULL, exePath, MAX_PATH);
            fs::path configPath = fs::path(exePath).parent_path();
            return configPath.string();
        }
    }
}