#include    <SFML/Graphics.hpp>
#include    <string>
#include    <random>
#include    "constants.hpp"
#include    "background.hpp"

using namespace std::literals;

class creature {
    // static random number engine and bernoulli distribution
    static std::mt19937 mt;
    static std::bernoulli_distribution bd;

    float xv{4.0f};
    float yv{4.0f};

    // SFML vector
    sf::Vector2f velocity;

    // SFML circe shape
    sf::CircleShape circle;

    public:

    creature(float x, float y){
        // set initial position and velocity
        velocity = {xv, yv};
        circle.setPosition(x, y);

        // set parameters of circle
        circle.setRadius(5.0f);
        circle.setFillColor(sf::Color::Red);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(circle);
    }

    // compute new position
    void update() {
        xv = bd(mt) ? -xv : xv;
        yv = bd(mt) ? -yv : yv;

        circle.move({xv, yv});
    }

};

std::mt19937 creature::mt;
std::bernoulli_distribution creature::bd;


int main(int argc, char const *argv[])
{
    sf::RenderWindow game_window({constants::window_width, constants::window_height}, "Test"s);
    game_window.setFramerateLimit(60);
    creature ball(constants::ballx, constants::bally);
    background bg(0.0f, 0.0f);

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
        ball.update();
        bg.draw(game_window);
        ball.draw(game_window);
        game_window.display();   
    }
    return 0;
}
