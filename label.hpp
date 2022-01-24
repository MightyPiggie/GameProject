//
// Created by Isaak van Luijk on 19/01/2022.
//

#ifndef LABEL_HPP
#define LABEL_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "drawable.hpp"

class label : public drawable{
protected:
    std::string text_string;
    int size_char;
    bool rectangle_display;
    sf::Color text_color;
    sf::Color background_text_color;

    sf::RectangleShape rect_SFML;
    sf::Font font_text;
    sf::Text text_SFML;
public:
    label(sf::RenderWindow &window,
        sf::Vector2f position,
        std::string text_string,
        int size_char,
        sf::Color background_text_color,
        bool rectangle_display = true,
        sf::Color text_color = sf::Color::Black);

    void draw() override;
    void update_text(std::string new_value);
};

#endif
