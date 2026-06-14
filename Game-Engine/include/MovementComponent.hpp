#ifndef _MOVEMENT_COMPONENT_HPP_
#define _MOVEMENT_COMPONENT_HPP_

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

#endif /* _MOVEMENT_COMPONENT_HPP_ */