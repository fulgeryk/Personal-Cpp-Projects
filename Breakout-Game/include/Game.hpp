#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

namespace breakout::core
{
	class Game
	{
	private:
		sf::RenderWindow window;
		static constexpr int cell_size = 20;
		bool game_over = false;
	public:
		Game();
		void run();
	};
}