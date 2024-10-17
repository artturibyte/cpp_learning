#ifndef ENTITY_H
#define ENTITY_H
#include    "SFML/Graphics.hpp"


// abstract baseclass to represent all graphical entities on screen
class Entity{
    bool destroyed{false};
    protected:
    sf::Sprite sprite;
    public:
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

    // Helper function to get the bounding box of sprite
    [[nodiscard]] sf::FloatRect get_bounding_box() const noexcept;

    // Helper function to get the centre of a sprite
    [[nodiscard]] sf::Vector2f get_center() const noexcept;

    // Helper functions to get the edges of the sprite
    float left() const noexcept;
    float right() const noexcept;
    float top() const noexcept;
    float bottom() const noexcept;

    void destroy() noexcept;
    bool is_destroyed() const noexcept;

    [[nodiscard]] float x() const noexcept;
    [[nodiscard]] float y() const noexcept;

    virtual ~Entity() {};
};

class Moving_entity: public Entity
{
    protected:
    sf::Vector2f velocity;

    virtual void move_up() noexcept = 0;
    virtual void move_left() noexcept = 0;
    virtual void move_right() noexcept = 0;
    virtual void move_down() noexcept = 0;
};

#endif