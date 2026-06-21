#include "AssetManager.hpp"
#include <stdexcept>
AssetManager::~AssetManager()
{
    clear();
}
void AssetManager::clear()
{
    if(fallbackTexture_ != nullptr)
    {
        SDL_DestroyTexture(fallbackTexture_);
        fallbackTexture_ = nullptr;
    }
    for(auto& texture : textures_)
    {
        if(texture.second != nullptr)
        {
            SDL_DestroyTexture(texture.second);
        }
    }
    textures_.clear();
}
void AssetManager::loadFallbackTexture(SDL_Renderer* renderer, const std::string& path)
{
    if(fallbackTexture_ != nullptr)
    {
        SDL_DestroyTexture(fallbackTexture_);
        fallbackTexture_ = nullptr;
    }
    SDL_Surface* surface = IMG_Load(path.c_str());
    if(surface == nullptr) throw std::runtime_error(IMG_GetError());
    fallbackTexture_ = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if(fallbackTexture_ == nullptr) throw std::runtime_error(SDL_GetError());
}
void AssetManager::loadTexture(SDL_Renderer* renderer, const std::string& id, const std::string& path)
{
    if(textures_.count(id))
    {
        return;
    }
    SDL_Surface* surface = IMG_Load(path.c_str());
    if(surface == nullptr) throw std::runtime_error(IMG_GetError());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if(texture == nullptr) throw std::runtime_error(SDL_GetError());
    textures_[id] = texture;
}
SDL_Texture* AssetManager::getTexture(const std::string& id)
{
    auto it = textures_.find(id);
    if(it != textures_.end())
    {
        return it->second;
    }
    return fallbackTexture_;
}