#include "MainMenuScene.hpp"

MainMenuScene::MainMenuScene(Renderer& renderer) : renderer_{renderer}
{
}
void MainMenuScene::handleEvent(const SDL_Event& event)
{
    if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
    {
        int mouseX = event.button.x;
        int mouseY = event.button.y;

        if(isPointInsideRect(mouseX, mouseY, startRect_))
        {
            selectedOption_ = MainMenuOption::StartGame;
            activateSelectedOption();
        }
        else if(isPointInsideRect(mouseX, mouseY, optionsRect_))
        {
            selectedOption_ = MainMenuOption::Options;
            activateSelectedOption();
        }
        else if(isPointInsideRect(mouseX, mouseY, quitRect_))
        {
            selectedOption_ = MainMenuOption::Quit;
            activateSelectedOption();
        }
    }
    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.scancode)
        {
        case SDL_SCANCODE_DOWN:
            selectNextOption();
            break;

        case SDL_SCANCODE_UP:
            selectPreviousOption();
            break;

        case SDL_SCANCODE_RETURN:
            activateSelectedOption();
            break;

        case SDL_SCANCODE_ESCAPE:
            sceneRequest_.type = SceneRequestType::Quit;
        }
    }
}
bool MainMenuScene::isPointInsideRect(int x, int y, const SDL_Rect& rect) const
{
    return x >= rect.x &&
           x <= rect.x + rect.w &&
           y >= rect.y &&
           y <= rect.y + rect.h;
}
void MainMenuScene::activateSelectedOption()
{
    switch(selectedOption_)
    {
    case MainMenuOption::StartGame:
        sceneRequest_.type = SceneRequestType::ChangeScene;
        sceneRequest_.targetScene = SceneType::Game;
        break;
    case MainMenuOption::Options:
        break;
    case MainMenuOption::Quit:
        sceneRequest_.type = SceneRequestType::Quit;
        break;
    }
}
void MainMenuScene::selectNextOption()
{
    switch(selectedOption_)
    {
    case MainMenuOption::StartGame:
        selectedOption_ = MainMenuOption::Options;
        break;
    case MainMenuOption::Options:
        selectedOption_ = MainMenuOption::Quit;
        break;
    case MainMenuOption::Quit:
        selectedOption_ = MainMenuOption::StartGame;
        break;
    }
}
void MainMenuScene::selectPreviousOption()
{
    switch(selectedOption_)
    {
    case MainMenuOption::StartGame:
        selectedOption_ = MainMenuOption::Quit;
        break;
    case MainMenuOption::Options:
        selectedOption_ = MainMenuOption::StartGame;
        break;
    case MainMenuOption::Quit:
        selectedOption_ = MainMenuOption::Options;
        break;
    }
}

void MainMenuScene::update(float deltaTime)
{
}

void MainMenuScene::render()
{
    renderer_.drawRect(startRect_,
        selectedOption_ == MainMenuOption::StartGame ? 255 : 100,
        255, 255, 255);

    renderer_.drawRect(optionsRect_,
        selectedOption_ == MainMenuOption::Options ? 255 : 100,
        255, 255, 255);

    renderer_.drawRect(quitRect_,
        selectedOption_ == MainMenuOption::Quit ? 255 : 100,
        255, 255, 255);
}
SceneRequest MainMenuScene::getSceneRequest() const
{
    return sceneRequest_;
}

void MainMenuScene::clearSceneRequest()
{
    sceneRequest_.type = SceneRequestType::None;
}