#ifndef BALL_H
#define BALL_H

#include    "constants.hpp"
#include    "entity.hpp"

class Ball: public Moving_entity {
    private:
    static sf::Texture texture;

    public:

    // constructor:
    // Initial position of the ball.
    // SFML uses computer graphics convention,
    // (0, 0) is top left corner of the screen.
    // x to the right, y to downwards.
    Ball(float x, float y);

    // Implement pure virtual functions of entity
    void update() override;
    void draw(sf::RenderWindow& window) override;

    void move_up() noexcept override;
    void move_left() noexcept override;
    void move_right() noexcept override;
    void move_down() noexcept override;
};

#endif