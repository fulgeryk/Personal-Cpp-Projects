#ifndef _SPRITE_COMPONENT_HPP_
#define _SPRITE_COMPONENT_HPP_

#include "Component.hpp"
#include <cstdint>

class SpriteComponent : public Component
{
public:
    SpriteComponent(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255U);
    ~SpriteComponent() override = default;

    SpriteComponent(const SpriteComponent&) = delete;
    SpriteComponent& operator=(const SpriteComponent&) = delete;

    SpriteComponent(SpriteComponent&&) noexcept = default;
    SpriteComponent& operator=(SpriteComponent&&) noexcept = default;

    uint8_t getR() const;
    uint8_t getG() const;
    uint8_t getB() const;
    uint8_t getA() const;
private:
    uint8_t r_;
    uint8_t g_;
    uint8_t b_;
    uint8_t a_;
};

#endif /* _SPRITE_COMPONENT_HPP_ */