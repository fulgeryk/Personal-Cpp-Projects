#include "MainMenuScene.hpp"

MainMenuScene::MainMenuScene(Renderer& renderer) : renderer_{renderer}
{
}
void MainMenuScene::handleEvent(const SDL_Event& event)
{
    if(event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.scancode == SDL_SCANCODE_RETURN)
        {
            sceneRequest_.type = SceneRequestType::ChangeScene;
            sceneRequest_.targetScene = SceneType::Game;
        }
        else if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
        {
            sceneRequest_.type = SceneRequestType::Quit;
        }
    }
}

void MainMenuScene::update(float deltaTime)
{
}

void MainMenuScene::render()
{
    SDL_Rect rect{300, 200, 400, 120};

    renderer_.drawRect(rect, 255, 255, 255, 255);
}
SceneRequest MainMenuScene::getSceneRequest() const
{
    return sceneRequest_;
}

void MainMenuScene::clearSceneRequest()
{
    sceneRequest_.type = SceneRequestType::None;
}