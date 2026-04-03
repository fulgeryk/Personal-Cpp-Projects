#pragma once

#include "Position.hpp"
#include <iostream>
#include <cmath>
namespace breakout::entities
{
	class Ball
	{
	private:
		breakout::core::Position position;
		float radius;
		float velocity_x;
		float velocity_y;
	public:
		Ball(const breakout::core::Position& pos, float rad, float vx, float vy) : position{ pos }, radius{ rad }, velocity_x{ vx }, velocity_y{ vy } {}
		void move(float delta_time);
		const breakout::core::Position& getPosition() const;
		void reverse_velocity_x();
		void reverse_velocity_y();
	};
}
