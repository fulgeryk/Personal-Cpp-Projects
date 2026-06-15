#include "Entity.hpp"

bool Entity::isActive() const
{
    return active_;
}
void Entity::setActive(bool active)
{
    active_ = active;
}