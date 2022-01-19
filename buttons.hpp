#ifndef BUTTONS_HPP
#define BUTTONS_HPP

#include <functional>
#include <string>
#include <SFML/Graphics.hpp>

#include "drawable.hpp"

class buttons : public drawable{
protected:
    std::function<void(void)> function;
    std::string name;
    sf::RectangleShape rect;
    sf::Color kleur;
    sf::Color hover;

    sf::Font font;
    sf::Text txt;

public:
    buttons(sf::RenderWindow &window,
            sf::Vector2f position,
            sf::Vector2f size,
            std::function<void(void)> function,
            std::string name,
            sf::Color kleur,
            sf::Color hover = sf::Color::Black);

    void draw() override;

    void update() override;

    void update_coins(uint16_t coins);
};

#endif