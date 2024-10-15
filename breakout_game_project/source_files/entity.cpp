#include    "entity.hpp"

sf::FloatRect entity::get_bounding_box() const noexcept {
    return sprite.getGlobalBounds();
}

sf::Vector2f entity::get_center() const noexcept {
    auto box = get_bounding_box();
    return {box.width/2, box.height/2};
}

bool entity::is_destroyed() const noexcept {return destroyed;}
void entity::destroy() noexcept {destroyed = true;}

float entity::left() const noexcept {
    auto box = get_bounding_box();
    return x() - box.width / 2;
}

float entity::right() const noexcept {
    auto box = get_bounding_box();
    return x() + box.width / 2;
}

float entity::top() const noexcept {
    auto box = get_bounding_box();
    return y() - box.height / 2;
}

float entity::bottom() const noexcept {
    auto box = get_bounding_box();
    return y() + box.height / 2;
}

float entity::x() const noexcept { return sprite.getPosition().x;}
float entity::y() const noexcept { return sprite.getPosition().y;}