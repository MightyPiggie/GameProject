#include "obstacle.hpp"
#include <iostream>

obstacle::obstacle(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, std::string filename):
    game_drawable(window, position, size), filename(filename)
{
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setPosition(position);
    window.draw(sprite);
}

void obstacle::draw() {
    sprite.setPosition(position);
    window.draw(sprite);
}

sf::FloatRect obstacle::getbounds() {
    std::cout << "obstacle: " << sprite.getGlobalBounds().left << " : " << sprite.getGlobalBounds().top << std::endl;
    return obs.getGlobalBounds();
}


