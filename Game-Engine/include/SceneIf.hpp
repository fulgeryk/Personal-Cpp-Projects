#ifndef SCENE_IF_HPP
#define SCENE_IF_HPP

#include "SDL2/SDL.h"
#include "SceneRequest.hpp"

class SceneIf
{
public:
    SceneIf() = default;
    virtual ~SceneIf() = default;

    SceneIf(const SceneIf&) = delete;
    SceneIf& operator=(const SceneIf&) = delete;

    SceneIf(SceneIf&&) = delete;
    SceneIf& operator=(SceneIf&&) = delete;

    virtual void handleEvent(const SDL_Event& event) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;

    virtual SceneRequest getSceneRequest() const = 0;
    virtual void clearSceneRequest() = 0;
};
#endif /* SCENE_IF_HPP */
