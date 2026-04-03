#include "Paddle.hpp"

namespace breakout::entities
{
	void Paddle::setDirection(Direction new_direction)
	{
		direction = new_direction;
	}
	void Paddle::move(float delta_time)
	{
		float misc = speed * delta_time;
		if (direction == Direction::Left)
		{
			position.x -= misc;
		}
		else if (direction == Direction::Right)
		{
			position.x += misc;
		}
	}
	const breakout::core::Position& Paddle::getPosition() const
	{
		return position;
	}
	void Paddle::clampX(float min, float max)
	{
		if (position.x < min) { position.x = min; }
		if (position.x + width > max) { position.x = max - width; }
	}
}