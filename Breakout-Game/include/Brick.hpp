#pragma once

#include "Position.hpp"

namespace breakout::entities
{
	struct Brick
	{
		breakout::core::Position position;
		float width;
		float height;
		bool destroyed = false;
		Brick(const breakout::core::Position& pos, float w, float h) : position{ pos }, width{ w }, height{ h } {}
	};
}
