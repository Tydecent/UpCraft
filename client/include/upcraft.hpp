#pragma once
#include <string>
#include <json.hpp>
using json = nlohmann::json;
#include <fstream>

#include "httplib.h"


namespace UpCraft {
    class UpCraft {
    public:
        UpCraft(const std::string& url) {
            this -> url = url;
        }

        bool health() {
            httplib::Client cli(url);

            auto res = cli.Get("/health");

            if (res && res -> status == 200) {
                return 0;
            } else {
                return res -> status;
            }
        }

        std::string get_version() {
            httplib::Client cli(url);

            auto res = cli.Get("/api/v1/get_version");

            if (res && res -> status == 200) {
                std::string body = res -> body;
                json j = json::parse(body);
                return j["version"];

            } else {
                return "unknown";
            }
        }

        int download_update() {
            httplib::Client cli(url);
            std::ofstream ofs("update", std::ios::binary);
            if (!ofs) {
                return -1;
            }
            ofs.clear();

            auto res = cli.Get("/path/to/large-file", [&](const char *data, size_t data_length) {
                ofs.write(data, data_length); 
                return true; 
            }); 

            ofs.close();

            if (res && res -> status == 200) {
                return 0;
            } else {
                return res -> status;
            }       
        }

    private:
        std::string url;
    };

}