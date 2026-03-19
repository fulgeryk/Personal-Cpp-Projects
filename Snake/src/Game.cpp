#include "Game.hpp"
#include <optional>

constexpr uint16_t width = 800;
constexpr uint16_t height = 600;
Game::Game() : window(sf::VideoMode({ width, height }), "Snake Game"), snake {Position((width/cell_size)/2, (height/cell_size)/2)}
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
		for (const auto& [x, y] : snake.snake_body())
		{
			float screen_x = x * cell_size;
			float screen_y = y * cell_size;
			sf::RectangleShape show_snake;
			show_snake.setSize(sf::Vector2f(cell_size, cell_size));
			show_snake.setFillColor(sf::Color::White);
			show_snake.setPosition({ screen_x, screen_y });
			window.draw(show_snake);
		}
		window.display();
	}
}