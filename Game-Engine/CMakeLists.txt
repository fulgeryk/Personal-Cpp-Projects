cmake_minimum_required(VERSION 3.20)

project(GameEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)

add_executable(GameEngine
    src/Engine.cpp
    src/Window.cpp
    src/Renderer.cpp
    src/Entity.cpp
    src/Player.cpp
    src/EntityManager.cpp
    src/main.cpp
)

target_include_directories(GameEngine PRIVATE include)

target_link_libraries(GameEngine PRIVATE
    SDL2::SDL2
)