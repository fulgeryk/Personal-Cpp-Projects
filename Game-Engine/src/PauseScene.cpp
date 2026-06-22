#include "PauseScene.hpp"

PauseScene::PauseScene(Renderer& renderer) : renderer_{renderer}
{
}
void PauseScene::handleEvent(const SDL_Event& event)
{
}

void PauseScene::update(float deltaTime)
{
}

void PauseScene::render()
{
    SDL_Rect rect{300, 200, 400, 120};

    renderer_.drawRect(rect, 255, 255, 0, 255);
}