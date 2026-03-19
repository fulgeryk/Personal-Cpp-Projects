#pragma once
#include "Direction.hpp"
#include "Position.hpp"
#include <vector>

class Snake {
private:
	std::vector<Position> body;
	Direction direction;
public:
	Snake(Position start) :
		body{ Position(start.x - 2, start.y), Position(start.x - 1, start.y), Position(start.x, start.y) },
		direction{ Direction::Right }
	{
	};
	void setDirection(Direction new_direction);
	void move(bool eat);
	const std::vector<Position>& snake_body() const;
	const Position& head() const;
};
