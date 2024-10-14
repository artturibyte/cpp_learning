#include    <SFML/Graphics.hpp>
#include    <string>
#include    <random>
#include    "constants.hpp"
#include    "background.hpp"
#include    "ball.hpp"
#include    "paddle.hpp"
#include    "interactions.hpp"

using namespace std::literals;

int main(int argc, char const *argv[])
{
    sf::RenderWindow game_window({constants::window_width, constants::window_height}, "Test"s);
    game_window.setFramerateLimit(60);
    ball ball(0, 0);
    paddle paddle(0, constants::window_height);
    background bg(0, 0);

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
        }

        // Calculate directions
        ball.update();
        paddle.update();
        handle_collision(ball, paddle);

        // Draw new frame
        bg.draw(game_window);
        ball.draw(game_window);
        paddle.draw(game_window);
        game_window.display();   
    }
    return 0;
}
