#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include "drawable.hpp"
#include "gamestates.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class obstacle : public game_drawable {
private:
    sf::RectangleShape obs;
    const std::string filename;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    obstacle(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, object_states object_state, std::string filename );
    void draw() override;
    sf::FloatRect getbounds() override;
};

#endif