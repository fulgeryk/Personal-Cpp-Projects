#ifndef _TRANSFORM_COMPONENT_HPP_
#define _TRANSFORM_COMPONENT_HPP_

#include "Component.hpp"

class TransformComponent : public Component
{
public:
    TransformComponent(float x, float y, float width, float height);
    ~TransformComponent() override = default;

    TransformComponent(const TransformComponent&) = delete;
    TransformComponent& operator=(const TransformComponent&) = delete;

    TransformComponent(TransformComponent&&) noexcept = default;
    TransformComponent& operator=(TransformComponent&&) noexcept = default;

    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;

    void move(float dx, float dy);
private:
    float x_;
    float y_;
    float width_;
    float height_;
};


#endif /* _TRANSFORM_COMPONENT_HPP_ */