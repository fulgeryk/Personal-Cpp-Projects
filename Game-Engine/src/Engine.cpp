#include "Engine.hpp"
#include <stdexcept>

namespace textures
{
    constexpr const char* MissingTexturePath{"assets/textures/missing_texture.png"};
    constexpr const char* PlayerTexture{"assets/textures/player.png"};
}

Engine::Engine()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0) throw std::runtime_error(SDL_GetError());
    if(IMG_Init(IMG_INIT_PNG) == 0) throw std::runtime_error(IMG_GetError());
    window_ = std::make_unique<Window>("Game Engine", 800, 600);
    renderer_ = std::make_unique<Renderer>(*window_);
    assetManager_.loadFallbackTexture(renderer_->getNativeRender(), textures::MissingTexturePath);

    #ifdef DEBUG
    auto* testTexture = assetManager_.getTexture("No texture");
    if(testTexture == nullptr)
    {
        throw std::runtime_error("Fallback texture failed");
    }
    #endif /* DEBUG */

    assetManager_.loadTexture(renderer_->getNativeRender(), "player", textures::PlayerTexture);

    #ifdef DEBUG
    auto* playerTexture = assetManager_.getTexture("player");
    if(playerTexture == nullptr)
    {
        throw std::runtime_error("Player texture failed");
    }
    #endif /* DEBUG */

    Entity& entity1 = entityManager_.createEntity();
    entity1.addComponent<TransformComponent>(300.0f, 100.0f, 50.0f, 50.0f);
    entity1.addComponent<SpriteComponent>(255, 0, 0);
    entity1.addComponent<TextureComponent>(assetManager_.getTexture("undefined texture"));
    Entity& entity2 = entityManager_.createEntity();
    entity2.addComponent<TransformComponent>(500.0f, 300.0f, 80.0f, 40.0f);
    entity2.addComponent<SpriteComponent>(0, 255, 0);
    entity2.addComponent<TextureComponent>(assetManager_.getTexture("undefined texture"));
    player_.addComponent<TextureComponent>(assetManager_.getTexture("player"));
    lastFrameTime_ = SDL_GetTicks();
}
Engine::~Engine()
{
    assetManager_.clear();

    renderer_.reset();
    window_.reset();

    IMG_Quit();
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
        auto* playerTexture = player_.getComponent<TextureComponent>();
        if(playerTransform != nullptr)
        {
            if(playerTexture != nullptr)
            {
                SDL_Rect srcRect{playerTexture->getSrcRect()};
                SDL_Rect dstRect{
                    static_cast<int>(playerTransform->getX()),
                    static_cast<int>(playerTransform->getY()),
                    static_cast<int>(playerTransform->getWidth() * playerTexture->getScale()),
                    static_cast<int>(playerTransform->getHeight() * playerTexture->getScale())
                };
                renderer_->drawTexture(
                    playerTexture->getTexture(),
                    srcRect,
                    dstRect
                );
            }
            else if (playerSprite != nullptr)
            {
                SDL_Rect rect{
                    static_cast<int>(playerTransform->getX()),
                    static_cast<int>(playerTransform->getY()),
                    static_cast<int>(playerTransform->getWidth()),
                    static_cast<int>(playerTransform->getHeight())
                };
                renderer_->drawRect(
                    rect,
                    playerSprite->getR(),
                    playerSprite->getG(),
                    playerSprite->getB(),
                    playerSprite->getA()
                );
            }
        }
        for(const auto& entity : entityManager_.getEntities())
        {
            if(entity->isActive())
            {
                auto* transform = entity->getComponent<TransformComponent>();
                auto* sprite = entity->getComponent<SpriteComponent>();
                auto* texture = entity->getComponent<TextureComponent>();
                texture->setScale(0.5f);
                if(transform != nullptr)
                {
                    if(texture != nullptr)
                    {
                        SDL_Rect srcRect{texture->getSrcRect()};
                        SDL_Rect dstRect{
                            static_cast<int>(transform->getX()),
                            static_cast<int>(transform->getY()),
                            static_cast<int>(transform->getWidth() * texture->getScale()),
                            static_cast<int>(transform->getHeight() * texture->getScale())
                        };
                        renderer_->drawTexture(
                            texture->getTexture(),
                            srcRect,
                            dstRect
                        );
                    }
                    else if(sprite != nullptr)
                    {
                        SDL_Rect rect{
                            static_cast<int>(transform->getX()),
                            static_cast<int>(transform->getY()),
                            static_cast<int>(transform->getWidth()),
                            static_cast<int>(transform->getHeight())
                        };
                        renderer_->drawRect( 
                            rect,
                            sprite->getR(),
                            sprite->getG(),
                            sprite->getB(),
                            sprite->getA()
                        );
                    }  
                }              
            }
        }
        renderer_->present();
    }
}