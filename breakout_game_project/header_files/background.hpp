#ifndef BACKGROUND_H
#define BACKGROUND_H
#include    <SFML/Graphics.hpp>
#include    "entity.hpp"

class background: public entity {
    private:
    static sf::Texture texture;
    public:
        background(float x, float y);

        // Implement pure virtual functions
        void update() override;
        void draw(sf::RenderWindow& window) override;

        
};


#endif