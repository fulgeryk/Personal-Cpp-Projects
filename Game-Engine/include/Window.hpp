#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include <SDL2/SDL.h>
#include <string>

class Window
{
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    Window(Window&& other) noexcept;
    Window& operator=(Window&& other) noexcept;

    SDL_Window* getNativeWindow() const;

private:
    SDL_Window* window_{nullptr};
};

#endif /* _WINDOW_HPP_ */