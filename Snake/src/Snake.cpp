#include "Snake.hpp"

void Snake::setDirection(Direction new_direction)
{
	if ((direction == Direction::Right && new_direction == Direction::Left) || (direction == Direction::Left && new_direction == Direction::Right) ||
		(direction == Direction::Up && new_direction == Direction::Down) || (direction == Direction::Down && new_direction == Direction::Up) )
		return;
	direction = new_direction;
}
void Snake::move(bool eat)
{
	Position head = body.back();
	switch (direction)
	{
	case Direction::Up:
		head.y -= 1;
		break;
	case Direction::Down:
		head.y += 1;
		break;
	case Direction::Left:
		head.x -= 1;
		break;
	case Direction::Right:
		head.x += 1;
		break;
	}
	body.push_back(head);
	if (!eat)
	{
		body.erase(body.begin());
	}
}
const std::vector<Position>& Snake::snake_body() const
{
	return body;
}
const Position& Snake::head() const
{
	return body.back();
}
Position Snake::next_head() const
{
	Position head = body.back();
	switch (direction)
	{
	case Direction::Up:
		head.y -= 1;
		break;
	case Direction::Down:
		head.y += 1;
		break;
	case Direction::Left:
		head.x -= 1;
		break;
	case Direction::Right:
		head.x += 1;
		break;
	}
	return head;
}