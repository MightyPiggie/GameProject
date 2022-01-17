#include "obstacle.hpp"

obstacle::obstacle(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size):
    drawable(window, position, size)
{
    obs.setSize(size);
    obs.setPosition(position);

}

void obstacle::draw() {
	window.draw(obs);
}

sf::FloatRect obstacle::getbounds() {
    return obs.getGlobalBounds();
}


