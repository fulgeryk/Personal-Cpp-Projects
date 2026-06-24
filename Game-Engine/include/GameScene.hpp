#ifndef GAME_SCENE_HPP
#define GAME_SCENE_HPP

#include "SceneIf.hpp"
#include "Player.hpp"
#include "EntityManager.hpp"
#include "TextureComponent.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include "MovementComponent.hpp"
#include "AssetManager.hpp"
#include "Renderer.hpp"
#include <memory>

class GameScene : public SceneIf
{
public:
    GameScene(AssetManager& assetManager, Renderer& renderer);
    ~GameScene() override = default;

    GameScene(const GameScene&) = delete;
    GameScene& operator=(const GameScene&) = delete;

    GameScene(GameScene&&) = delete;
    GameScene& operator=(GameScene&&) = delete;

    void handleEvent(const SDL_Event& event) override;
    void update(float deltaTime) override;
    void render() override;

    SceneRequest getSceneRequest() const override;
    void clearSceneRequest() override;

private:
    void handlePlayerMovement(float deltaTime);

    std::unique_ptr<Player> player_;
    std::unique_ptr<EntityManager> entityManager_;
    AssetManager& assetManager_;
    Renderer& renderer_;
    SceneRequest sceneRequest_;
};
#endif /* GAME_SCENE_HPP */