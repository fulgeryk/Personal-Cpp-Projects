#include "Ball.hpp"

namespace breakout::entities
{
	void Ball::move(float delta_time)
	{
		position.x += velocity_x * delta_time;
		position.y += velocity_y * delta_time;
	}
	const breakout::core::Position& Ball::getPosition() const
	{
		return position;
	}
	void Ball::reverse_velocity_x()
	{
		velocity_x *= -1;
	}
	void Ball::reverse_velocity_y()
	{
		velocity_y *= -1;
	}
}