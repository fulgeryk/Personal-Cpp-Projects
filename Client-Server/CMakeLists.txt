cmake_minimum_required(VERSION 3.20)

project(client_server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(server
    src/server.cpp
)
add_executable(client
    src/client.cpp
)

target_include_directories(server PRIVATE include)
target_include_directories(client PRIVATE include)
