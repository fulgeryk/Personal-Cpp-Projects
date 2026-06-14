#include "Entity.hpp"
#include <stdexcept>

void Entity::addTransform(float x, float y, float width, float height)
{
    auto transform = std::make_unique<TransformComponent>(x, y, width, height);
    components_.push_back(std::move(transform));
}
TransformComponent* Entity::getTransform()
{
    for(auto& component : components_)
    {
        auto* transform = dynamic_cast<TransformComponent*>(component.get());
        if (transform != nullptr)
        {
            return transform;
        }
    }
    return nullptr;
}
void Entity::addSprite(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    auto sprite = std::make_unique<SpriteComponent>(r, g, b, a);
    components_.push_back(std::move(sprite));
}
SpriteComponent* Entity::getSprite()
{
    for(auto& component : components_)
    {
        auto* sprite = dynamic_cast<SpriteComponent*>(component.get());
        if(sprite != nullptr)
        {
            return sprite;
        }
    }
    return nullptr;
}
void Entity::addMovement(float speed)
{
    auto movement = std::make_unique<MovementComponent>(speed);
    components_.push_back(std::move(movement));
}
MovementComponent* Entity::getMovement()
{
    for(auto& component : components_)
    {
        auto* movement = dynamic_cast<MovementComponent*>(component.get());
        if(movement != nullptr)
        {
            return movement;
        }
    }
    return nullptr;
}

bool Entity::isActive() const
{
    return active_;
}
void Entity::setActive(bool active)
{
    active_ = active;
}