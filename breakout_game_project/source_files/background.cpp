#include "background.hpp"

// initialize static data
sf::Texture background::texture;

background::background(float x, float y): Entity() {
    // load the texture
    texture.loadFromFile("background.jpg");

    sprite.setTexture(texture);

    // use x, y for inital position of background
    sprite.setPosition(x, y);
};

void background::update() {
    // nothing to do here
}

void background::draw(sf::RenderWindow& window) {
    // ask the window to draw sprite
    window.draw(sprite);
}
