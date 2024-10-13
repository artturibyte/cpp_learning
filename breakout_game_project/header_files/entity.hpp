#ifndef ENTITY_H
#define ENTITY_H
#include    "SFML/Graphics.hpp"


// abstract baseclass to represent graphical entities
class entity{
    protected:
    sf::Sprite sprite;
    public:
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

    virtual ~entity() {};
};

#endif