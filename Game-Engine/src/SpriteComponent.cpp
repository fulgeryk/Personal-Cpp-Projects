#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r_{r}, g_{g}, b_{b}, a_{a} {}
uint8_t SpriteComponent::getA() const
{
    return a_;
}
uint8_t SpriteComponent::getR() const
{
    return r_;
}
uint8_t SpriteComponent::getG() const
{
    return g_;
}
uint8_t SpriteComponent::getB() const
{
    return b_;
}