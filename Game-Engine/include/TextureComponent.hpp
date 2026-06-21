#ifndef TEXTURE_COMPONENT_HPP
#define TEXTURE_COMPONENT_HPP

#include "Component.hpp"
#include "SDL2/SDL.h"

class TextureComponent : public Component
{
public:
    explicit TextureComponent(SDL_Texture* texture);
    ~TextureComponent() override = default;

    TextureComponent(const TextureComponent&) = delete;
    TextureComponent& operator=(const TextureComponent&) = delete;

    TextureComponent(TextureComponent&&) = default;
    TextureComponent& operator=(TextureComponent&&) = default;

    SDL_Texture* getTexture() const;

    void setSrcRect(int x, int y, int width, int height);
    SDL_Rect getSrcRect() const;

    void setScale(float scale);
    float getScale() const;
private:
    SDL_Texture* texture_;
    SDL_Rect srcRect_;
    float scale_{1.0f};
};
#endif /* TEXTURE_COMPONENT_HPP */