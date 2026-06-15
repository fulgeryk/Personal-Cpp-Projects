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
    Entity& entity1 = entityManager_.createEntity();
    entity1.addComponent<TransformComponent>(300.0f, 100.0f, 50.0f, 50.0f);
    entity1.addComponent<SpriteComponent>(255, 0, 0);
    Entity& entity2 = entityManager_.createEntity();
    entity2.addComponent<TransformComponent>(500.0f, 300.0f, 80.0f, 40.0f);
    entity2.addComponent<SpriteComponent>(0, 255, 0);
    lastFrameTime_ = SDL_GetTicks();
}
Engine::~Engine()
{
    renderer_.reset();
    window_.reset();
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
        auto* playerTransform = player_.getComponent<TransformComponent>();
        auto* playerSprite = player_.getComponent<SpriteComponent>();
        if (playerTransform != nullptr && playerSprite != nullptr)
        {
            renderer_->drawRect(
                static_cast<int>(playerTransform->getX()),
                static_cast<int>(playerTransform->getY()),
                static_cast<int>(playerTransform->getWidth()),
                static_cast<int>(playerTransform->getHeight()),
                playerSprite->getR(),
                playerSprite->getG(),
                playerSprite->getB(),
                playerSprite->getA()
            );
        }
        for(const auto& entity : entityManager_.getEntities())
        {
            if(entity->isActive())
            {
                auto* transform = entity->getComponent<TransformComponent>();
                auto* sprite = entity->getComponent<SpriteComponent>();
                if(transform != nullptr && sprite != nullptr)
                {
                    renderer_->drawRect(
                        static_cast<int>(transform->getX()),
                        static_cast<int>(transform->getY()),
                        static_cast<int>(transform->getWidth()),
                        static_cast<int>(transform->getHeight()),
                        sprite->getR(),
                        sprite->getG(),
                        sprite->getB(),
                        sprite->getA()
                    );  
                }              
            }
        }
        renderer_->present();
    }
}