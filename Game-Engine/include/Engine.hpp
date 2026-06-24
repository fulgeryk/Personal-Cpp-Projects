#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Window.hpp"
#include "Renderer.hpp"
#include "Player.hpp"
#include "AssetManager.hpp"
#include "SceneIf.hpp"
#include "GameScene.hpp"
#include "MainMenuScene.hpp"
#include "PauseScene.hpp"
#include "SceneType.hpp"
#include "SceneRequest.hpp"
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
    void changeScene(SceneType sceneType);

    bool running_{false};
    std::unique_ptr<Window> window_;
    std::unique_ptr<Renderer> renderer_;
    AssetManager assetManager_;
    uint32_t lastFrameTime_{0};
    std::unique_ptr<SceneIf> currentScene_;
}; 

#endif /* ENDINGE_HPP */