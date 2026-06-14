#include "MovementComponent.hpp"

MovementComponent::MovementComponent(float speed) : speed_{speed} {}
float MovementComponent::getSpeed() const
{
    return speed_;
}