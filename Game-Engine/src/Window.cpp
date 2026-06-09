#include "Window.hpp"
#include <stdexcept>

Window::Window(const std::string& title, int width, int height)
{
    window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if(window_ == nullptr)
    {
        throw std::runtime_error(SDL_GetError());
    }
}
Window::Window(Window&& other) noexcept : window_{other.window_}
{
    other.window_ = nullptr;
}
Window& Window::operator=(Window&& other) noexcept
{
    if(this == &other)
    {
        return *this;
    }
    if(window_ != nullptr)
    {
        SDL_DestroyWindow(window_);
    }

    window_ = other.window_;
    other.window_ = nullptr;

    return *this;
}
Window::~Window()
{
    if(window_ != nullptr)
    {
        SDL_DestroyWindow(window_);
    }
}
SDL_Window* Window::getNativeWindow() const
{
    return window_;
}