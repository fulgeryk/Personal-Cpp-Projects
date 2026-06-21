#include "TextureComponent.hpp"

TextureComponent::TextureComponent(SDL_Texture* texture) : texture_{texture} 
{
    SDL_QueryTexture(texture_, nullptr, nullptr, &srcRect_.w, &srcRect_.h);
    srcRect_.x = 0;
    srcRect_.y = 0;
};
void TextureComponent::setSrcRect(int x, int y, int width, int height)
{
    srcRect_.x = x;
    srcRect_.y = y;
    srcRect_.w = width;
    srcRect_.h = height;
}
void TextureComponent::setScale(float scale)
{
    scale_ = scale;
}
float TextureComponent::getScale() const
{
    return scale_;
}
SDL_Rect TextureComponent::getSrcRect() const
{
    return srcRect_;
}
SDL_Texture* TextureComponent::getTexture() const
{
    return texture_;
}