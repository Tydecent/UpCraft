cmake_minimum_required(VERSION 3.10)
project(UpCraft_Client_include_Example)

set(CMake_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(COMMON_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/include                             # upcraft.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/cpp-httplib             # httplib.h
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/json/include/nlohmann/  # nlohmann/json.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/json/include/           # fuck
)

add_executable(UpCraftClient 
               src/main.cpp
               src/utils.cpp)


target_include_directories(example PRIVATE ${COMMON_INCLUDES})

if (WIN32)
    # Windows下cpp-httplib需要链接ws2_32.lib
    target_link_libraries(example ws2_32)
endif()