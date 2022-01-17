#ifndef BUTTONS_HPP
#define BUTTONS_HPP

#include "drawable.hpp"

class buttons : public drawable{
protected:
    sf::RectangleShape rect;
    sf::Color kleur;
    sf::Color hover;
    sf::Font font;
    sf::Text txt;
public:
    buttons(sf::RenderWindow &window,
            sf::Vector2f position,
            sf::Vector2f size,
            sf::Color kleur,
            sf::Color hover = sf::Color::Black);

    void draw() override;

    void update() override;
};

#endif