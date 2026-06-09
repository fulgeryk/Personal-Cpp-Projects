#ifndef _ENGINE_HPP_
#define _ENGINE_HPP_

#include "Window.hpp"
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
    bool running_{false};
    std::unique_ptr<Window> window_;
}; 

#endif /* _ENDINGE_HPP_ */