#include "upcraft.hpp"
#include <iostream>

int main() {
    UpCraft::UpCraft updater("http://localhost:5000");

    // 健康检查
    if (!updater.health()) {
        std::cout << "Server is up.\n";
    } else {
        std::cerr << "Server health check failed.\n";
        return 1;
    }

    // 获取版本
    std::string version = updater.get_version();
    std::cout << "Available version: " << version << "\n";

    // 下载更新
    int result = updater.download_update();
    if (result == 0) {
        std::cout << "Download completed.\n";
    } else {
        std::cerr << "Download failed with code: " << result << "\n";
    }

    return 0;
}