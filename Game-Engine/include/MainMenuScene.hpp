#ifndef MAIN_MENU_SCENE_HPP
#define MAIN_MENU_SCENE_HPP

#include "SceneIf.hpp"
#include "Renderer.hpp"

enum class MainMenuOption
{
    StartGame,
    Options,
    Quit
};

class MainMenuScene : public SceneIf
{
public:
    MainMenuScene(Renderer& renderer);
    ~MainMenuScene() override = default;

    MainMenuScene(const MainMenuScene&) = delete;
    MainMenuScene& operator=(const MainMenuScene&) = delete;

    MainMenuScene(MainMenuScene&&) = delete;
    MainMenuScene& operator=(MainMenuScene&&) = delete;

    void handleEvent(const SDL_Event& event) override;
    void update(float deltaTime) override;
    void render() override;

    SceneRequest getSceneRequest() const override;
    void clearSceneRequest() override;
private:
    void selectNextOption();
    void selectPreviousOption();
    void activateSelectedOption();

    bool isPointInsideRect(int x, int y, const SDL_Rect& rect) const;

    Renderer& renderer_;
    SceneRequest sceneRequest_;
    MainMenuOption selectedOption_{MainMenuOption::StartGame};
    SDL_Rect startRect_{300, 180, 400, 80};
    SDL_Rect optionsRect_{300, 280, 400, 80};
    SDL_Rect quitRect_{300, 380, 400, 80};
};


#endif /* MAIN_MENU_SCENE_HPP */