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

void Brick::update() {
    
}

void Brick::draw(sf::RenderWindow& window){
    window.draw(sprite);
}