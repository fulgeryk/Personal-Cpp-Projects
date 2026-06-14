#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "Entity.hpp"

class Player : public Entity
{
public:
    Player(float x = 100.0f, float y = 100.0f, float width = 50.0f, float height = 50.0f, float speed = 200.0f,
           uint8_t r = 255U, uint8_t g = 255U, uint8_t b = 255U, uint8_t a = 255U);
    void move(float dx, float dy, float deltaTime);
};
#endif /* _PLAYER_HPP_ */