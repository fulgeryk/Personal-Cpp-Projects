#include "Entity.hpp"
#include <stdexcept>

Entity::Entity(float x, float y, float width, float height) : x{x}, y{y}, width{width}, height{height}
{
    if(width <= 0.0f)
    {
        throw std::invalid_argument("Entity width must be greater than 0");
    }
    if(height <= 0.0f)
    {
        throw std::invalid_argument("Entity height must be greater than 0");
    }
}
float Entity::getX() const
{
    return x;
}
float Entity::getY() const
{
    return y;
}
float Entity::getWidth() const
{
    return width;
}
float Entity::getHeight() const
{
    return height;
}
bool Entity::isActive() const
{
    return active_;
}
void Entity::move(float dx, float dy)
{
    x += dx;
    y += dy;
}
void Entity::setActive(bool active)
{
    active_ = active;
}