#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "drawable.hpp"
#include <SFML/Graphics.hpp>
class obstacle : public drawable {
private:
    sf::RectangleShape obs;

public:
    obstacle(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size);
    bool overlaps(sf::FloatRect global_bounds) const override;
};

#endif