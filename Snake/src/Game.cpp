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
	spawnFood();
	sf::RectangleShape show_food;
	show_food.setSize(sf::Vector2f(cell_size, cell_size));
	show_food.setFillColor(sf::Color::White);
	show_food.setPosition({ static_cast<float>(food.x * cell_size) , static_cast<float>(food.y * cell_size) });
	const sf::Font font("assets/Roboto.ttf");
	sf::Text text(font, "Game Over!");
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	auto bounds = text.getLocalBounds();
	text.setOrigin(sf::Vector2f(static_cast<float>(bounds.position.x + bounds.size.x / 2), static_cast<float>(bounds.position.y + bounds.size.y / 2)));
	text.setPosition(sf::Vector2f(static_cast<float>(width / 2), static_cast<float>(height / 2)));
	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (const auto* keypressed = event->getIf<sf::Event::KeyPressed>())
			{
				switch (keypressed->code)
				{
				case sf::Keyboard::Key::Up:
					snake.setDirection(Direction::Up);
					break;
				case sf::Keyboard::Key::Down:
					snake.setDirection(Direction::Down);
					break;
				case sf::Keyboard::Key::Left:
					snake.setDirection(Direction::Left);
					break;
				case sf::Keyboard::Key::Right:
					snake.setDirection(Direction::Right);
					break;
				}
			}
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
		window.draw(show_food);
		auto current_time = std::chrono::high_resolution_clock::now();
		std::chrono::milliseconds delay(150);
		if (current_time - last_move_time > delay)
		{
			Position next_head = snake.next_head();
			if (next_head.x < 0 || (next_head.x >= (width / cell_size)) || next_head.y < 0 || (next_head.y >= (height / cell_size)))
			{
				game_over = true;
			}
			for (const auto& b : snake.snake_body())
			{
				if (next_head == b)
				{
					game_over = true;
					break;
				}
			}
			if(!game_over)
			{
				if (next_head == food)
				{
					snake.move(true);
					spawnFood();
					show_food.setPosition({ static_cast<float>(food.x * cell_size) , static_cast<float>(food.y * cell_size) });
				}
				else
				{
					snake.move(false);
				}
				last_move_time = current_time;
			}
			else
			{
				window.draw(text);
			}
		}
		window.display();
	}
}
void Game::spawnFood()
{
	bool valid = false;
	while(!valid)
	{
		int randomwidth = rand() % (width / cell_size);
		int randomheight = rand() % (height / cell_size);
		food = Position(randomwidth, randomheight);
		valid = true;
		for (const auto& vec : snake.snake_body())
		{
			if (vec == food)
				valid = false;
		}
	}
}