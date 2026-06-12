#include "Player.hpp"

Player::Player(float x , float y, float width, float height, float speed) : Entity(x, y, width, height), speed_{speed} {}

void Player::move(float dx, float dy, float deltaTime)
{
    Entity::move(dx * speed_ * deltaTime,
                 dy * speed_ * deltaTime);
}