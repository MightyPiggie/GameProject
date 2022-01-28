#ifndef BUTTONS_HPP
#define BUTTONS_HPP

#include <functional>
#include <string>
#include <SFML/Graphics.hpp>

#include "drawable.hpp"

/// buttons class, heritage van drawable
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
    /**
     * @brief Construct a new buttons object
     * 
     * @param window 
     * @param char_size 
     * @param position 
     * @param function 
     * @param name 
     * @param kleur 
     * @param hover 
     */
    buttons(sf::RenderWindow &window,
             int char_size,
            sf::Vector2f position,
            std::function<void(void)> function,
            std::string name,
            sf::Color kleur,
            sf::Color hover = sf::Color::Black);
    /**
     * @brief 
     * 
     */
    void draw() override;

    /**
     * @brief 
     * 
     */
    void update() override;

    /**
     * @brief 
     * 
     * @param coins 
     */
    void update_coins(uint16_t coins);
};

#endif