#ifndef MAIN_MENU_SCENE_HPP
#define MAIN_MENU_SCENE_HPP

#include "SceneIf.hpp"
#include "Renderer.hpp"

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
    Renderer& renderer_;
    SceneRequest sceneRequest_;
};


#endif /* MAIN_MENU_SCENE_HPP */