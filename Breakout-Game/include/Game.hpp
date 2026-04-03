#pragma once

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"
#include "Ball.hpp"
#include <chrono>

namespace breakout::core
{
	class Game
	{
	private:
		sf::RenderWindow window;
		bool game_over = false;
		breakout::entities::Paddle pad;
		breakout::entities::Ball ball;
		std::chrono::high_resolution_clock::time_point last_move_time;
	public:
		Game();
		void run();
	};
}