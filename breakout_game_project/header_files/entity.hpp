#ifndef ENTITY_H
#define ENTITY_H
#include    "SFML/Graphics.hpp"


// abstract baseclass to represent all graphical entities on screen
class entity{
    protected:
    sf::Sprite sprite;
    public:
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

    // Helper function to get the bounding box of sprite
    [[nodiscard]] sf::FloatRect get_bounding_box() const noexcept;

    // Helper function to get the centre of a sprite
    [[nodiscard]] sf::Vector2f get_center() const noexcept;

    [[nodiscard]] float x() const noexcept;
    [[nodiscard]] float y() const noexcept;

    virtual ~entity() {};
};

class moving_entity: public entity
{
    protected:
    sf::Vector2f velocity;
};


#endif