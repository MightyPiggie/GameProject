//
// Created by Isaak van Luijk on 19/01/2022.
//

#ifndef V2CPSE2_EXAMPLES_LABEL_HPP
#define V2CPSE2_EXAMPLES_LABEL_HPP

#include "drawable.hpp"

class label : public drawable{
protected:
    std::string text_string;
    int size_char;
    sf::Color text_color;
    sf::Color hover_color;

    sf::RectangleShape rect_SFML;
    sf::Font font_text;
    sf::Text text_SFML;
public:
    label(sf::RenderWindow &window,
          sf::Vector2f position,
          sf::Vector2f size_rect,
          std::string text_string,
          int size_char,
          sf::Color hover_color,
          sf::Color text_color = sf::Color::Black);

    void draw() override;

    void update() override;
};


#endif //V2CPSE2_EXAMPLES_LABEL_HPP
