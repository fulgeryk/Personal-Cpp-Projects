#include "GameScene.hpp"

GameScene::GameScene(AssetManager& assetManager, Renderer& renderer) : assetManager_{assetManager}, renderer_{renderer}
{
    player_ = std::make_unique<Player>();
    entityManager_ = std::make_unique<EntityManager>();
    Entity& entity1 = entityManager_->createEntity();
    entity1.addComponent<TransformComponent>(300.0f, 100.0f, 50.0f, 50.0f);
    entity1.addComponent<SpriteComponent>(255, 0, 0);
    entity1.addComponent<TextureComponent>(assetManager_.getTexture("undefined texture"));
    entity1.getComponent<TextureComponent>()->setScale(0.5f);
    Entity& entity2 = entityManager_->createEntity();
    entity2.addComponent<TransformComponent>(500.0f, 300.0f, 80.0f, 40.0f);
    entity2.addComponent<SpriteComponent>(0, 255, 0);
    entity2.addComponent<TextureComponent>(assetManager_.getTexture("undefined texture"));
    entity2.getComponent<TextureComponent>()->setScale(0.6f);
    player_->addComponent<TextureComponent>(assetManager_.getTexture("player"));
}
void GameScene::handleEvent(const SDL_Event& event)
{

}
void GameScene::handlePlayerMovement(float deltaTime)
{
    const Uint8* keyboardState = SDL_GetKeyboardState(nullptr);
        if(keyboardState[SDL_SCANCODE_A])
        {
            player_->move(-1.0f, 0.0f, deltaTime);
        }
        if(keyboardState[SDL_SCANCODE_D])
        {
            player_->move(1.0f, 0.0f, deltaTime);
        }
        if(keyboardState[SDL_SCANCODE_W])
        {
            player_->move(0.0f, -1.0f, deltaTime);
        }
        if(keyboardState[SDL_SCANCODE_S])
        {
            player_->move(0.0f, 1.0f, deltaTime);
        }
}
void GameScene::update(float deltaTime)
{
    handlePlayerMovement(deltaTime);

}
void GameScene::render()
{
    auto* playerTransform = player_->getComponent<TransformComponent>();
    auto* playerSprite = player_->getComponent<SpriteComponent>();
    auto* playerTexture = player_->getComponent<TextureComponent>();
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
            renderer_.drawTexture(
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
            renderer_.drawRect(
                rect,
                playerSprite->getR(),
                playerSprite->getG(),
                playerSprite->getB(),
                playerSprite->getA()
            );
        }
    }
    for(const auto& entity : entityManager_->getEntities())
    {
        if(entity->isActive())
        {
            auto* transform = entity->getComponent<TransformComponent>();
            auto* sprite = entity->getComponent<SpriteComponent>();
            auto* texture = entity->getComponent<TextureComponent>();
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
                    renderer_.drawTexture(
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
                    renderer_.drawRect( 
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
}