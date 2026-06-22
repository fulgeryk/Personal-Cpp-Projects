#include "MainMenuScene.hpp"

MainMenuScene::MainMenuScene(Renderer& renderer) : renderer_{renderer}
{
}
void MainMenuScene::handleEvent(const SDL_Event& event)
{
}

void MainMenuScene::update(float deltaTime)
{
}

void MainMenuScene::render()
{
    SDL_Rect rect{300, 200, 400, 120};

    renderer_.drawRect(rect, 255, 255, 255, 255);
}