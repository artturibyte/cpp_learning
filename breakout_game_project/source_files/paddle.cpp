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

void paddle::move_up() noexcept {}

void paddle::move_down() noexcept {}

void paddle::move_left() noexcept {
    velocity.x = -constants::paddle_speed;
}

void paddle::move_right() noexcept {
    velocity.x = constants::paddle_speed;
}

