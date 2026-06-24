#ifndef PAUSE_SCENE_HPP
#define PAUSE_SCENE_HPP

#include "SceneIf.hpp"
#include "Renderer.hpp"

class PauseScene : public SceneIf 
{
public:
    PauseScene(Renderer& renderer);
    ~PauseScene() override = default;

    PauseScene(const PauseScene&) = delete;
    PauseScene& operator=(const PauseScene&) = delete;

    PauseScene(PauseScene&&) = delete;
    PauseScene& operator=(PauseScene&&) = delete;

    void handleEvent(const SDL_Event& event) override;
    void update(float deltaTime) override;
    void render() override;

    SceneRequest getSceneRequest() const override;
    void clearSceneRequest() override;
private:
    Renderer& renderer_;
    SceneRequest sceneRequest_;
};

#endif /* PAUSE_SCENE_HPP */