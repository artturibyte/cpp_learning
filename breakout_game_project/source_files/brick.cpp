#include    "brick.hpp"

//Initialize static data
sf::Texture brick::texture;

brick::brick(float x, float y) {
    // load texture
    texture.loadFromFile("brick01.png");
    sprite.setTexture(texture);

    // Set initial positions & velocity
    sprite.setPosition(x, y);
    sprite.setOrigin(get_center());
}

void brick::update() {
    
}

void brick::draw(sf::RenderWindow& window){
    window.draw(sprite);
}