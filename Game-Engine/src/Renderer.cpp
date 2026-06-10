#include "Renderer.hpp"
#include <stdexcept>

Renderer::Renderer(Window& window)
{
    renderer_ = SDL_CreateRenderer(window.getNativeWindow(), -1, SDL_RENDERER_ACCELERATED);
    if(renderer_ == nullptr)
    {
        throw std::runtime_error(SDL_GetError());
    }
}
Renderer::~Renderer()
{
    if(renderer_ != nullptr)
    {
        SDL_DestroyRenderer(renderer_);
    }
}
Renderer::Renderer(Renderer&& other) noexcept : renderer_{other.renderer_}
{
    other.renderer_ = nullptr;
}
Renderer& Renderer::operator=(Renderer&& other) noexcept
{
    if(this == &other)
    {
        return *this;
    }
    if(renderer_ != nullptr)
    {
        SDL_DestroyRenderer(renderer_);
    }
    renderer_ = other.renderer_;
    other.renderer_ = nullptr;
    return *this;
}
SDL_Renderer* Renderer::getNativeRender() const
{
    return renderer_;
}
void Renderer::clear()
{
    SDL_SetRenderDrawColor(
        renderer_,
        0,
        0,
        0,
        255
    );
    SDL_RenderClear(renderer_);
}
void Renderer::present()
{
    SDL_RenderPresent(renderer_);
}
void Renderer::drawRect(int x, int y, int width, int height)
{
    SDL_Rect rect{
        x,
        y,
        width,
        height
    };
    SDL_SetRenderDrawColor(
        renderer_,
        255,
        255,
        255,
        255
    );
    SDL_RenderFillRect(renderer_, &rect);
}