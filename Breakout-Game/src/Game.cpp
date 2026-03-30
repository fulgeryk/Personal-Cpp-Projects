#include "Game.hpp"
#include <optional>

constexpr uint16_t width = 800;
constexpr uint16_t height = 600;

namespace breakout::core
{
	Game::Game() : window(sf::VideoMode({ width, height }), "Breakout Game")
	{
		window.setFramerateLimit(60);
	}
	void Game::run()
	{
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    window.close();
            }
            window.clear(sf::Color::Black);
            window.display();
        }
	}
}