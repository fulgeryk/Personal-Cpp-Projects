#ifndef ASSET_MANAGER_HPP
#define ASSET_MANAGER_HPP

#include <unordered_map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class AssetManager
{
public:
    AssetManager() = default;
    ~AssetManager();

    AssetManager(const AssetManager&) = delete;
    AssetManager& operator=(const AssetManager&) = delete;

    AssetManager(AssetManager&&) noexcept = delete;
    AssetManager& operator=(AssetManager&&) noexcept = delete;

    void loadFallbackTexture(SDL_Renderer* renderer, const std::string& path);

    void loadTexture(SDL_Renderer* renderer, const std::string& id, const std::string& path);
    SDL_Texture* getTexture(const std::string& id);
    void clear();
private:
    std::unordered_map<std::string, SDL_Texture*> textures_;
    SDL_Texture* fallbackTexture_ = nullptr;
};
#endif /* ASSET_MANAGER_HPP */
