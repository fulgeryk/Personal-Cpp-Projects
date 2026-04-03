#include <iostream>
#include "Position.hpp"

namespace breakout::entities
{
	class Paddle
	{
	public:
		enum class Direction
		{
			Left,
			Right,
			None
		};
	private:
		breakout::core::Position position;
		float width;
		float height;
		float speed;
		Direction direction;
	public:
		Paddle(const breakout::core::Position& pos, float width, float height, float speed) : position{ pos }, width{ width }, height{ height }, speed{ speed }, direction{ Direction::None } {}
		void setDirection(Direction new_direction);
		void move(float delta_time);
		const breakout::core::Position& getPosition() const;
		void clampX(float min, float max);
	};
}