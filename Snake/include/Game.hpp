#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Snake.hpp"
#include <cstdlib>
#include <chrono>

class Game
{
private:
	sf::RenderWindow window;
	static constexpr int cell_size = 20;
	Snake snake;
	std::chrono::high_resolution_clock::time_point last_move_time = std::chrono::high_resolution_clock::now();
	Position food;
	bool game_over = false;
public:
	Game();
	void run();
	void spawnFood();
	void resetGame();
};
