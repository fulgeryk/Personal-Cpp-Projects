#ifndef TRANSFORM_COMPONENT_HPP
#define TRANSFORM_COMPONENT_HPP

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


#endif /* TRANSFORM_COMPONENT_HPP */