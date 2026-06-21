#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "Window.hpp"
#include "SDL2/SDL.h"

class Renderer
{
public:
    explicit Renderer(Window& window);
    ~Renderer();

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    Renderer(Renderer&& other) noexcept;
    Renderer& operator=(Renderer&& other) noexcept;

    void clear();
    void present();
    void drawRect(const SDL_Rect& rect, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    void drawTexture(SDL_Texture* texture, const SDL_Rect& srcRect, const SDL_Rect& dstRect);

    SDL_Renderer* getNativeRender() const;
private:
    SDL_Renderer* renderer_{nullptr};
};

#endif /* RENDERER_HPP */