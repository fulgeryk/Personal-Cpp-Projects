#pragma once

#include <SFML/Graphics.hpp>
#include "Snake.hpp"

class Game
{
private:
	sf::RenderWindow window;
	static constexpr int cell_size = 20;
	Snake snake;
public:
	Game();
	void run();
};