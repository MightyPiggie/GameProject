#ifndef WINDOW_PART_HPP
#define WINDOW_PART_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "drawable.hpp"

class window_part : public drawable{
protected:
    sf::RectangleShape rect;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    window_part(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f size, sf::Color color = sf::Color::Green);
    window_part(sf::RenderWindow& window, sf::Vector2f position,std::string filename);

    void draw() override;
};

#endif