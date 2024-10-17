#include    "paddle.hpp"
#include    "constants.hpp"

sf::Texture Paddle::texture;

Paddle::Paddle(float x, float y) {
    texture.loadFromFile("paddle.png");
    sprite.setTexture(texture);
    sprite.setPosition(x, y - constants::paddle_height);

    velocity = {constants::paddle_speed, 0};

    sprite.setOrigin(get_center());
}

void Paddle::update() {
    Paddle::process_player_input();
    sprite.move(velocity);
}

void Paddle::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}


// Process player keyboard input
// Left arrow key, negative velocity
// Right arrow key, positive velocity
void Paddle::process_player_input() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        if (x() >= 0) {
            move_left();
        }
        else {
            velocity.x = 0;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        if (x() <= constants::window_width) {
            move_right();
        }
        else {
            velocity.x = 0;
        }
    }
    else {
        velocity.x = 0;
    }
}

void Paddle::move_up() noexcept {}

void Paddle::move_down() noexcept {}

void Paddle::move_left() noexcept {
    velocity.x = -constants::paddle_speed;
}

void Paddle::move_right() noexcept {
    velocity.x = constants::paddle_speed;
}

