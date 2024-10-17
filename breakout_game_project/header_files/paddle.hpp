#ifndef PADDLE_H
#define PADDLE_H

#include    "entity.hpp"

class Paddle: public Moving_entity {
    private:
    static sf::Texture texture;

    public:
    // Initial position of the paddle
    Paddle(float x, float y);

    // Implement pure virtual functions of entity
    void update() override;
    void draw(sf::RenderWindow& window) override;

    // input from player
    void process_player_input();

    void move_up() noexcept override;
    void move_left() noexcept override;
    void move_right() noexcept override;
    void move_down() noexcept override;
};


#endif