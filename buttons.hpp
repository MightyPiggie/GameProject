#ifndef BUTTONS_HPP
#define BUTTONS_HPP

#include "drawable.hpp"
#include <functional>
class buttons : public drawable{
protected:
    std::function<void(void)> function;
    std::string name;
    sf::RectangleShape rect;
    sf::Color kleur;
    sf::Color hover;
    int char_size;
    sf::Font font;
    sf::Text txt;

public:
    buttons(sf::RenderWindow &window,
             int char_size,
            sf::Vector2f position,
            std::function<void(void)> function,
            std::string name,
            sf::Color kleur,
            sf::Color hover = sf::Color::Black);

    void draw() override;

    void update() override;

    void update_coins(uint16_t coins){
        txt.setString(std::to_string(coins) + " C");
    }
};

#endif