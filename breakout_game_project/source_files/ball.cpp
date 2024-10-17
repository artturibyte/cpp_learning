#include    "ball.hpp"
#include    "constants.hpp"

//Initialize static data
sf::Texture Ball::texture;

Ball::Ball(float x, float y) {
    // load texture
    texture.loadFromFile("ball.png");
    sprite.setTexture(texture);

    // Set initial positions & velocity
    sprite.setPosition(x, y);
    velocity = {constants::ball_speed, constants::ball_speed};
}

void Ball::update() {
    // Move position
    sprite.move(velocity);

    // Check that if the Ball has moved over the boundaries of the window,
    // change its direction to opposite.
    if (x() < 0 || x() > constants::window_width) {
        velocity.x = -velocity.x;
    }
    // Check also for y direction
    if (y() < 0 || y() > constants::window_height) {
        velocity.y = -velocity.y;
    }
};

void Ball::draw(sf::RenderWindow& window) {
    window.draw(sprite);
};

void Ball::move_up() noexcept {
    velocity.y = -constants::ball_speed;
}

void Ball::move_left() noexcept {
    velocity.x = -constants::ball_speed;
}

void Ball::move_right() noexcept {
    velocity.x = constants::ball_speed;
}

void Ball::move_down() noexcept {
    velocity.y = constants::ball_speed;
}