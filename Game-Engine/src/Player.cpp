#include "Player.hpp"

Player::Player(float x , float y, float width, float height, float speed,
               uint8_t r, uint8_t g, uint8_t b, uint8_t a )
{
    addTransform(x, y, width, height);
    addSprite(r, g, b, a);
    addMovement(speed);
}

void Player::move(float dx, float dy, float deltaTime)
{
    auto* transform = getTransform();
    auto* movement = getMovement();
    if(transform != nullptr && movement != nullptr)
    {
        transform->move(dx * movement->getSpeed() * deltaTime,
                        dy * movement->getSpeed() * deltaTime);
    }
}