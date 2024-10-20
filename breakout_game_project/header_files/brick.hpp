#ifndef BRICK_H
#define BRICK_H

#include    "entity.hpp"

class Brick: public Entity {
    private:
    static sf::Texture texture;
    int strength{2};

    public:
    // constructors
    Brick(float x, float y);

    void set_strength(int s);
    void weaken();
    bool is_too_weak();

    void update() override;
    void draw(sf::RenderWindow& window) override;

};

#endif