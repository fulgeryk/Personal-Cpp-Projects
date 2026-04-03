#include "Game.hpp"
#include <optional>

constexpr uint16_t width = 800;
constexpr uint16_t height = 600;
constexpr float paddle_width = 100.f;
constexpr float paddle_height = 20.f;
constexpr float paddle_speed = 400.f;
constexpr uint8_t offset = 30;
constexpr float pad_position_width = (width / 2 - paddle_width / 2);
constexpr float pad_position_height = (static_cast<float>(height) - paddle_height - static_cast<float>(offset));

namespace breakout::core {
    Game::Game() : window(sf::VideoMode({ width, height }), "Breakout Game"), last_move_time{ std::chrono::steady_clock::now() }, pad{ breakout::core::Position(pad_position_width, pad_position_height), paddle_width , paddle_height, paddle_speed }

	{
		window.setFramerateLimit(60);
	}
	void Game::run()
	{
        sf::RectangleShape show_pad;
        show_pad.setSize(sf::Vector2f(paddle_width, paddle_height));
        show_pad.setFillColor(sf::Color::White);
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
                {
                    pad.setDirection(breakout::entities::Paddle::Direction::Left);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
                {
                    pad.setDirection(breakout::entities::Paddle::Direction::Right);
                }
                else
                {
                    pad.setDirection(breakout::entities::Paddle::Direction::None);
                }
                if (event->is<sf::Event::Closed>())
                    window.close();
            }
            window.clear(sf::Color::Black);
            window.draw(show_pad);
            auto time_now = std::chrono::steady_clock::now();
            auto delta = std::chrono::duration<float>(time_now - last_move_time).count();
            pad.move(delta);
            auto pos = pad.getPosition();
            show_pad.setPosition({ pos.x, pos.y });
            last_move_time = time_now;
            window.display();
        }
	}
}