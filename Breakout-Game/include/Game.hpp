#pragma once

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"

namespace breakout::core
{
	class Game
	{
	private:
		sf::RenderWindow window;
		bool game_over = false;
		breakout::entities::Paddle pad;
	public:
		Game();
		void run();
	};
}