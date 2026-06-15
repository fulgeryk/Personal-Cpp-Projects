#include "Entity.hpp"
#include <stdexcept>

bool Entity::isActive() const
{
    return active_;
}
void Entity::setActive(bool active)
{
    active_ = active;
}