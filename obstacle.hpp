#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "drawable.hpp"
#include <SFML/Graphics.hpp>
class obstacle : public game_drawable {
private:
    sf::RectangleShape obs;

public:
    obstacle(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size);
    void draw() override;
    sf::FloatRect getbounds() override;
};

#endif