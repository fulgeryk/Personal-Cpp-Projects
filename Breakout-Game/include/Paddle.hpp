#include <iostream>
#include "Position.hpp"
#include <vector>

namespace breakout::entities
{
	class Paddle
	{
	private:
		enum class Direction
		{
			Left,
			Right,
			None
		};
		breakout::core::Position position;
		float width;
		float height;
		float speed;
		Direction direction;
	public:
		Paddle(const breakout::core::Position& pos, float width, float height, float speed) : position{ pos }, width{ width }, height{ height }, speed{ speed }, direction{ Direction::None } {}
		void setDirection(Direction new_direction);
		void move(float delta_time);
	};
}