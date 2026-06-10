#include "Engine.hpp"
#include <stdexcept>

Engine::Engine()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        throw std::runtime_error(SDL_GetError());
    }
    window_ = std::make_unique<Window>("Game Engine", 800, 600);
    renderer_ = std::make_unique<Renderer>(*window_);
    lastFrameTime_ = SDL_GetTicks();
}
Engine::~Engine()
{
    SDL_Quit();
}
float Engine::calculateDeltaTime()
{
    uint32_t currentFrameTime = SDL_GetTicks();
    float deltaTime = (currentFrameTime - lastFrameTime_) / 1000.0f;
    lastFrameTime_ = currentFrameTime;
    return deltaTime;
}
void Engine::handlePlayerMovement(float deltaTime)
{
    const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
    if(keyboardState[SDL_SCANCODE_A])
    {
        player_.move(-1.0f, 0.0f, deltaTime);
    }
    if(keyboardState[SDL_SCANCODE_D])
    {
        player_.move(1.0f, 0.0f, deltaTime);
    }
    if(keyboardState[SDL_SCANCODE_W])
    {
        player_.move(0.0f, -1.0f, deltaTime);
    }
    if(keyboardState[SDL_SCANCODE_S])
    {
        player_.move(0.0f, 1.0f, deltaTime);
    }
}
void Engine::run()
{   
    running_ = true;
    SDL_Event event;
    while(running_)
    {
        float deltaTime = calculateDeltaTime();
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                running_ = false;
            }
        }
        handlePlayerMovement(deltaTime);
        renderer_->clear();
        renderer_->drawRect(
            static_cast<int>(player_.x),
            static_cast<int>(player_.y),
            static_cast<int>(player_.width),
            static_cast<int>(player_.height)
        );
        renderer_->present();
    }
}