#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Window.hpp"
#include "Renderer.hpp"
#include "Player.hpp"
#include "EntityManager.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include "TextureComponent.hpp"
#include "AssetManager.hpp"
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
    EntityManager entityManager_;
    AssetManager assetManager_;
    uint32_t lastFrameTime_{0};
}; 

#endif /* ENDINGE_HPP */