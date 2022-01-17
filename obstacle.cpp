#include "obstacle.hpp"

obstacle::obstacle(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size):
    game_drawable(window, position, size)
{
    obs.setSize(size);
    obs.setPosition(position);

}

void obstacle::draw() {
    obs.setPosition(position);
	window.draw(obs);
}

sf::FloatRect obstacle::getbounds() {
    return obs.getGlobalBounds();
}


