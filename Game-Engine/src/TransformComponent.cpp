#include "TransformComponent.hpp"
#include <stdexcept>

TransformComponent::TransformComponent(float x, float y, float width, float height) : x_{x}, y_{y}, width_{width}, height_{height}
{
    if(width_ <= 0.0f)
    {
        throw std::invalid_argument("Transform Component width must be greater than 0");
    }
    if(height_ <= 0.0f)
    {
        throw std::invalid_argument("Transform Component height must be greater than 0");
    }
}
float TransformComponent::getX() const
{
    return x_;
}
float TransformComponent::getY() const
{
    return y_;
}
float TransformComponent::getWidth() const
{
    return width_;
}
float TransformComponent::getHeight() const
{
    return height_;
}
void TransformComponent::move(float dx, float dy)
{
    x_ += dx;
    y_ += dy;
}