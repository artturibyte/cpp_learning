#ifndef PADDLE_H
#define PADDLE_H

#include    "entity.hpp"

class paddle: public moving_entity {
    private:
    static sf::Texture texture;

    public:
    // Initial position of the paddle
    paddle(float x, float y);

    // Implement pure virtual functions of entity
    void update() override;
    void draw(sf::RenderWindow& window) override;

    // input from player
    void process_player_input();

};


#endif