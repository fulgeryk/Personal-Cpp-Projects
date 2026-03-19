cmake_minimum_required(VERSION 3.20)

project(snake_game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(snake_game
	src/main.cpp
	src/Game.cpp
	src/Snake.cpp
)

target_include_directories(snake_game PRIVATE include)

find_package(fmt CONFIG REQUIRED)
find_package(SFML CONFIG REQUIRED COMPONENTS Graphics)

target_link_libraries(snake_game PRIVATE 
	fmt::fmt 
	SFML::Graphics
)