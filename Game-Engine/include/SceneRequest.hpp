#ifndef SCENE_REQUEST_HPP
#define SCENE_REQUEST_HPP

#include "SceneType.hpp"

enum class SceneRequestType
{
    None,
    ChangeScene,
    Quit
};

struct SceneRequest
{
    SceneRequestType type{SceneRequestType::None};
    SceneType targetScene{SceneType::Game};
};

#endif /* SCENE_REQUEST_HPP */
