#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include "MovementComponent.hpp"
#include <vector>
#include <memory>

class Entity
{
public:
    Entity() = default;
    
    Entity(const Entity&) = delete;
    Entity& operator=(const Entity&) = delete;

    Entity(Entity&& other) noexcept = default;
    Entity& operator=(Entity&& other) noexcept = default;

    virtual ~Entity() = default;

    bool isActive() const;

    void addTransform(float x, float y, float width, float height);
    TransformComponent* getTransform();

    void addSprite(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255U);
    SpriteComponent* getSprite();

    void addMovement(float speed);
    MovementComponent* getMovement();

    void setActive(bool active);
private:
    bool active_{true};
    std::vector<std::unique_ptr<Component>> components_;
};

#endif /* _ENTITY_HPP_ */