cmake_minimum_required(VERSION 3.20)

project(breakout_game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(breakout_game
	src/main.cpp
	src/Game.cpp
)

target_include_directories(breakout_game PRIVATE include)

find_package(fmt CONFIG REQUIRED)
find_package(SFML CONFIG REQUIRED COMPONENTS Graphics)

target_link_libraries(breakout_game PRIVATE
	fmt::fmt
	SFML::Graphics
)