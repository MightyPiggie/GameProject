//
// Created by Isaak van Luijk on 19/01/2022.
//

#include "draw_sprite.hpp"

draw_sprite::draw_sprite(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f size,
                         const std::string filename):
                         drawable(window, position, size),
                         filename(filename)
                         {}

void draw_sprite::draw() {
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setPosition(position);
    window.draw(sprite);
}