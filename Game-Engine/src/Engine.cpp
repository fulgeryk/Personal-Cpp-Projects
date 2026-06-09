#include "Engine.hpp"
#include <stdexcept>

Engine::Engine()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        throw std::runtime_error(SDL_GetError());
    }
    window_ = std::make_unique<Window>("Game Engine", 800, 600);
}
Engine::~Engine()
{
    SDL_Quit();
}
void Engine::run()
{   
    running_ = true;
    SDL_Event event;
    while(running_)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                running_ = false;
            }
        }
    }
}