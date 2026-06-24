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
    window_ = std::make_unique<Window>("Game Engine", 1024, 768);
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
    changeScene(SceneType::MainMenu);
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
void Engine::changeScene(SceneType sceneType)
{
    switch(sceneType)
    {
        case SceneType::Game:
            currentScene_ = std::make_unique<GameScene>(assetManager_, *renderer_);
            break;
        case SceneType::MainMenu:
            currentScene_ = std::make_unique<MainMenuScene>(*renderer_);
            break;
        case SceneType::Pause:
            currentScene_ = std::make_unique<PauseScene>(*renderer_);
            break;
        default:
            throw std::runtime_error("Unknown scene type");
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
            currentScene_->handleEvent(event);
        }
        currentScene_->update(deltaTime);
        SceneRequest request = currentScene_->getSceneRequest();
        currentScene_->clearSceneRequest();
        if(request.type == SceneRequestType::ChangeScene)
        {
            changeScene(request.targetScene);
        }
        else if(request.type == SceneRequestType::Quit)
        {
            running_ = false;
        }
        renderer_->clear();
        currentScene_->render();
        renderer_->present();
    }
}