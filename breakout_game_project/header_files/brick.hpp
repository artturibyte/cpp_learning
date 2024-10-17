#ifndef BRICK_H
#define BRICK_H

#include    "entity.hpp"

class Brick: public Entity {
    private:
    static sf::Texture texture;

    public:
    // constructors
    Brick(float x, float y);

    void update() override;
    void draw(sf::RenderWindow& window) override;

};

#endif