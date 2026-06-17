#ifndef MOVEMENT_COMPONENT_HPP
#define MOVEMENT_COMPONENT_HPP

#include "Component.hpp"

class MovementComponent : public Component
{
public:
    explicit MovementComponent(float speed);
    ~MovementComponent() override = default;

    MovementComponent(const MovementComponent&) = delete;
    MovementComponent& operator=(const MovementComponent&) = delete;

    MovementComponent(MovementComponent&&) noexcept = default;
    MovementComponent& operator=(MovementComponent&&) noexcept = default;
    
    float getSpeed() const;
private:
    float speed_;
};

#endif /* MOVEMENT_COMPONENT_HPP */