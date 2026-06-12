#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "Entity.hpp"

class Player : public Entity
{
public:
    Player(float x = 100.0f, float y = 100.0f, float width = 50.0f, float height = 50.0f, float speed = 200.0f);
    void move(float dx, float dy, float deltaTime);

private:
    float speed_;
};
#endif /* _PLAYER_HPP_ */