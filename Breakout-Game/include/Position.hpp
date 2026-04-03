#pragma once

namespace breakout::core
{
	struct Position
	{
		float x;
		float y;
		Position(float x = 0, float y = 0) noexcept : x{ x }, y{ y } {};
		bool operator==(const Position& other) const
		{
			return x == other.x && y == other.y;
		}
	};
}
