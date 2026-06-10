#ifndef _ENGINE_HPP_
#define _ENGINE_HPP_

#include "Window.hpp"
#include "Renderer.hpp"
#include "Player.hpp"
#include <memory>

class Engine
{
public:
    Engine();
    ~Engine();

    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

    Engine(Engine&&) = delete;
    Engine& operator=(Engine&&) = delete;

    void run();
private:
    float calculateDeltaTime();
    void handlePlayerMovement(float deltaTime);
    bool running_{false};
    std::unique_ptr<Window> window_;
    std::unique_ptr<Renderer> renderer_;
    Player player_;
    uint32_t lastFrameTime_{0};
}; 

#endif /* _ENDINGE_HPP_ */