#include    "paddle.hpp"
#include    "constants.hpp"

sf::Texture paddle::texture;

paddle::paddle(float x, float y) {
    texture.loadFromFile("paddle.png");
    sprite.setTexture(texture);
    sprite.setPosition(x, y - constants::paddle_height);

    velocity = {constants::paddle_speed, 0};

    sprite.setOrigin(get_center());
}

void paddle::update() {
    paddle::process_player_input();
    sprite.move(velocity);
}

void paddle::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}


// Process player keyboard input
// Left arrow key, negative velocity
// Right arrow key, positive velocity
void paddle::process_player_input() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        if (x() >= 0) {
            velocity.x = -constants::paddle_speed;
        }
        else {
            velocity.x = 0;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        if (x() <= constants::window_width) {
            velocity.x = constants::paddle_speed;
        }
        else {
            velocity.x = 0;
        }
    }
    else {
        velocity.x = 0;
    }

}