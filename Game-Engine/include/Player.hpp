#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

struct Player
{
    Player(float x = 100.0f,
           float y = 100.0f,
           float width = 50.0f,
           float height = 50.0f,
           float speed = 200.0f)
        : x{x}
        , y{y}
        , width{width}
        , height{height}
        , speed{speed}
        {
        }
    float x;
    float y;

    float width;
    float height;

    float speed;
};
#endif /* _PLAYER_HPP_ */