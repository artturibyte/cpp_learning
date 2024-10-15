#include    <SFML/Graphics.hpp>
#include    <string>
#include    <random>
#include    <vector>
#include    "constants.hpp"
#include    "background.hpp"
#include    "ball.hpp"
#include    "paddle.hpp"
#include    "brick.hpp"
#include    "interactions.hpp"

using namespace std::literals;

int main(int argc, char const *argv[])
{
    sf::RenderWindow game_window({constants::window_width, constants::window_height}, "Test"s);
    game_window.setFramerateLimit(60);
    ball ball(constants::window_width/2, constants::window_height/2);
    paddle paddle(0, constants::window_height);
    background bg(0, 0);

    std::vector<brick>  brick_vec;

    for (size_t i = 0; i < constants::brick_colums; i++)
    {
        for (size_t j = 0; j < constants::brick_rows; j++)
        {
            // Calculatte brick position
            float x = constants::brick_offset + constants::brick_width * (i + 1);
            float y = constants::brick_height * (j + 1);
            brick_vec.emplace_back(x, y);
        }
        
    }
    

    while (game_window.isOpen())
    {
        game_window.clear(sf::Color::Black);

        sf::Event event;

        while (game_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                game_window.close();
                break;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                game_window.close();
                break;
            }

            if (event.type == sf::Event::Resized) {
            // Force window size
            game_window.setSize(sf::Vector2u(constants::window_width, constants::window_height)); 
            }
        }

        // Calculate directions
        ball.update();
        paddle.update();

        // Handle collisions
        handle_collision(ball, paddle);

        for (auto& b : brick_vec)
            handle_collision(ball, b);
        
        // Erase destroyed bricks
        brick_vec.erase(
            std::remove_if(begin(brick_vec), end(brick_vec), 
                [](const brick& b){ return b.is_destroyed();}), 
            end(brick_vec));

        // Draw new frame
        bg.draw(game_window);
        ball.draw(game_window);
        paddle.draw(game_window);

        for (auto b : brick_vec)
            b.draw(game_window);

        game_window.display();   
    }
    return 0;
}
