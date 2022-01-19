#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>

#include "drawable.hpp"

class menu : public drawable{
private:
    sf::RectangleShape rect;
public:
    menu(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f size);
    void draw() override;
};
#endif