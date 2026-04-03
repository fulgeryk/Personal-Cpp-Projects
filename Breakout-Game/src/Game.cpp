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

constexpr float left_boundary = 0.f;
constexpr float right_boundary = width;

constexpr float radius = 10.f; // radius of ball

constexpr float initial_ball_velocity_x = 200.f;
constexpr float initial_ball_velocity_y = -200.f;

constexpr float brick_width = 60.f;
constexpr float brick_height = 20.f;

constexpr int brick_rows = 5;
constexpr int brick_cols = 11;

constexpr float brick_spacing = 10.f;

constexpr float bricks_start_x = 20.f;
constexpr float bricks_start_y = 50.f;

namespace breakout::core {
    Game::Game() : window(sf::VideoMode({ width, height }), "Breakout Game"), last_move_time{ std::chrono::steady_clock::now() }
        , pad{ breakout::core::Position(pad_position_width, pad_position_height), paddle_width , paddle_height, paddle_speed }
        , ball{ breakout::core::Position(static_cast<float>(width / 2 - radius), static_cast<float>(height / 2 - radius)), radius, initial_ball_velocity_x, initial_ball_velocity_y }
	{
		window.setFramerateLimit(60);
        initBricks();
	}
	void Game::run()
	{
        sf::RectangleShape show_pad;
        show_pad.setSize(sf::Vector2f(paddle_width, paddle_height));
        show_pad.setFillColor(sf::Color::White);
        sf::CircleShape show_ball;
        show_ball.setRadius(radius);
        show_ball.setFillColor(sf::Color::White);
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    window.close();
            }
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
            window.clear(sf::Color::Black);
            for (const auto& brick : bricks)
            {
                if (!brick.destroyed)
                {
                    sf::RectangleShape show_brick;
                    show_brick.setSize(sf::Vector2f(brick_width, brick_height));
                    show_brick.setFillColor(sf::Color::White);
                    show_brick.setPosition({ brick.position.x, brick.position.y });
                    window.draw(show_brick);
                }
            }
            if (!game_over)
            {
                auto time_now = std::chrono::steady_clock::now();
                auto delta = std::chrono::duration<float>(time_now - last_move_time).count();
                pad.move(delta);
                pad.clampX(left_boundary, right_boundary);
                auto pos_pad = pad.getPosition();
                show_pad.setPosition({ pos_pad.x, pos_pad.y });
                ball.move(delta);
                auto pos_ball = ball.getPosition();
                if (pos_ball.x <= 0)
                {
                    ball.reverse_velocity_x();
                }
                if ((pos_ball.x + 2 * radius) >= width)
                {
                    ball.reverse_velocity_x();
                }
                if (pos_ball.y <= 0)
                {
                    ball.reverse_velocity_y();
                }
                if (pos_ball.y + 2 * radius >= pos_pad.y && 
                    ((pos_ball.x >= pos_pad.x && pos_ball.x <= pos_pad.x + paddle_width) || ( pos_ball.x + 2*radius >= pos_pad.x && pos_ball.x + 2* radius <= pos_pad.x + paddle_width)))
                {
                    ball.reverse_velocity_y();
                }
                for (auto& brick : bricks)
                {
                    if (!brick.destroyed)
                    {
                        if ((pos_ball.x <= brick.position.x + brick.width) &&
                            (pos_ball.x + 2 * radius >= brick.position.x) &&
                            (pos_ball.y <= brick.position.y + brick.height) &&
                            (pos_ball.y + 2 * radius >= brick.position.y))
                        {
                            brick.destroyed = true;
                            ball.reverse_velocity_y();
                            break;
                        }
                    }
                }
                if (pos_ball.y + 2 * radius >= height)
                {
                    game_over = true;
                }
                show_ball.setPosition({ pos_ball.x, pos_ball.y });
                last_move_time = time_now;
            }
            window.draw(show_pad);
            window.draw(show_ball);
            window.display();
        }
	}
    void Game::initBricks()
    {
        for (auto i = 0; i < brick_rows; ++i)
        {
            for (auto j = 0; j < brick_cols; ++j)
            {
                float x = bricks_start_x + j * (brick_width + brick_spacing);
                float y = bricks_start_y + i * (brick_height + brick_spacing);
                bricks.push_back(breakout::entities::Brick(breakout::core::Position(x, y), brick_width, brick_height));
            }
        }
    }
}
