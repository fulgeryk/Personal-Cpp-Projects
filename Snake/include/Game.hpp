#include <SFML/Graphics.hpp>
#pragma once

class Game
{
private:
	sf::RenderWindow window;
public:
	Game();
	void run();
};