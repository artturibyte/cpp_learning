#include    "brick.hpp"

//Initialize static data
sf::Texture Brick::texture;

Brick::Brick(float x, float y) {
    // load texture
    texture.loadFromFile("beer-bottle.png");
    sprite.setTexture(texture);

    // Set initial positions & velocity
    sprite.setPosition(x, y);
    sprite.setOrigin(get_center());
}

void Brick::weaken() {
    strength--;
}

void Brick::set_strength(int s){strength = s;};

bool Brick::is_too_weak() {return strength == 0;}

void Brick::update() {
    if (strength==2) {
        sprite.setColor(sf::Color{255, 255,  255, 255});
    }
    else if (strength==1) {
        sprite.setColor(sf::Color{255, 255, 255 , 155});
    }
}

void Brick::draw(sf::RenderWindow& window){
    window.draw(sprite);
}