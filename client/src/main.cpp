#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <cxxopts.hpp>

#include "upcraft.hpp"
#include "utils.h"

int main(int argc, char* argv[]) {
    // 处理命令行参数
    cxxopts::Options options("UpCraft", "A client for UpCraft");

    options.add_options()
        ("gv,get_version",  "Request the latest version from the server");

    auto result = options.parse(argc, argv);

    std::string current_exe_path = UpCraft::utils::get_current_exe_path();

    std::string config_path = current_exe_path + "/config.ini";

    std::string server_host = "";

    // 从配置文件读取服务器地址
    {
        char buffer[1024];
        GetPrivateProfileStringA("Server", "Host", "unknown", buffer, sizeof(buffer), config_path.c_str());
        server_host = buffer;
    }

    // 如果是unknown，则报错
    if (server_host == "unknown") {
        return 1;
    }

    UpCraft::UpCraft updater(server_host);

    // 健康检查
    auto health_result = updater.health();
    if (!health_result.success) return 2;

    // 获取最新版本
    std::string latest_version = updater.get_version();

    if (result.count("gv")) {
        std::cout << latest_version << std::endl;
        return 0;
    }

    // 下载最新版本

    if (result.count("d")) {
        updater.download_update();
        return 0;
    }

    return 0;
}