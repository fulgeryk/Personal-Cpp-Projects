#include "Player.hpp"

Player::Player(float x , float y, float width, float height, float speed,
               uint8_t r, uint8_t g, uint8_t b, uint8_t a )
{
    addComponent<TransformComponent>(x, y, width, height);
    addComponent<SpriteComponent>(r, g, b, a);
    addComponent<MovementComponent>(speed);
}

void Player::move(float dx, float dy, float deltaTime)
{
    auto* transform = getComponent<TransformComponent>();
    auto* movement = getComponent<MovementComponent>();
    if(transform != nullptr && movement != nullptr)
    {
        transform->move(dx * movement->getSpeed() * deltaTime,
                        dy * movement->getSpeed() * deltaTime);
    }
}