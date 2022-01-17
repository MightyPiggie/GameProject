#include "obstacle.hpp"

obstacle::obstacle(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size):
    drawable(window, position, size)
{
    obs.setSize(size);
    obs.setPosition(position);

}

bool obstacle::overlaps(sf::FloatRect global_bound) const {
    return obs.getGlobalBounds().intersects(global_bound);
}