#include    "entity.hpp"

sf::FloatRect Entity::get_bounding_box() const noexcept {
    return sprite.getGlobalBounds();
}

sf::Vector2f Entity::get_center() const noexcept {
    auto box = get_bounding_box();
    return {box.width/2, box.height/2};
}

bool Entity::is_destroyed() const noexcept {return destroyed;}
void Entity::destroy() noexcept {destroyed = true;}

float Entity::left() const noexcept {
    auto box = get_bounding_box();
    return x() - box.width / 2;
}

float Entity::right() const noexcept {
    auto box = get_bounding_box();
    return x() + box.width / 2;
}

float Entity::top() const noexcept {
    auto box = get_bounding_box();
    return y() - box.height / 2;
}

float Entity::bottom() const noexcept {
    auto box = get_bounding_box();
    return y() + box.height / 2;
}

float Entity::x() const noexcept { return sprite.getPosition().x;}
float Entity::y() const noexcept { return sprite.getPosition().y;}