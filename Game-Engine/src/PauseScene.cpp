#include "PauseScene.hpp"

PauseScene::PauseScene(Renderer& renderer) : renderer_{renderer}
{
}
void PauseScene::handleEvent(const SDL_Event& event)
{
    if(event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
        {
            sceneRequest_.type = SceneRequestType::ChangeScene;
            sceneRequest_.targetScene = SceneType::Game;
        }
        else if(event.key.keysym.scancode == SDL_SCANCODE_M)
        {
            sceneRequest_.type = SceneRequestType::ChangeScene;
            sceneRequest_.targetScene = SceneType::MainMenu;
        }
    }
}

void PauseScene::update(float deltaTime)
{
}

void PauseScene::render()
{
    SDL_Rect rect{300, 200, 400, 120};

    renderer_.drawRect(rect, 255, 255, 0, 255);
}

SceneRequest PauseScene::getSceneRequest() const
{
    return sceneRequest_;
}

void PauseScene::clearSceneRequest()
{
    sceneRequest_.type = SceneRequestType::None;
}