#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

class Entity
{
public:
    Entity(float x, float y, float width, float height);
    
    Entity(const Entity&) = delete;
    Entity& operator=(const Entity&) = delete;

    Entity(Entity&& other) noexcept = default;
    Entity& operator=(Entity&& other) noexcept = default;

    virtual ~Entity() = default;

    float getX() const;
    float getY() const;
    float getWidth() const;
    float getHeight() const;
    bool isActive() const;

    void move(float dx, float dy);
    void setActive(bool active);
private:
    float x;
    float y;
    float width;
    float height;
    bool active_{true};
};



#endif /* _ENTITY_HPP_ */