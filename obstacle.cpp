#include "obstacle.hpp"

#include <iostream>

obstacle::obstacle(sf::RenderWindow & window, sf::Vector2f position , sf::Vector2f size, shitty_fix_enum state_t, object_states object_state , std::string filename):
    game_drawable(window, position, size, state_t, object_state), filename(filename)
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
    return obs.getGlobalBounds();
}


