cmake_minimum_required(VERSION 3.20)

project(client_server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(server
    src/server_main.cpp
    src/Server.cpp
    src/Socket.cpp
)
add_executable(client
    src/client_main.cpp
    src/Client.cpp
    src/Socket.cpp
)

target_include_directories(server PRIVATE include)
target_include_directories(client PRIVATE include)
