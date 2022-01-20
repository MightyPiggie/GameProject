#include "label.hpp"

#include <iostream>

#include "simple_functions.hpp"

label::label(sf::RenderWindow &window,
        sf::Vector2f position,
        std::string text_string,
        int size_char,
        sf::Color hover_color,
        sf::Color text_color):
    drawable(window, position, {0,0}),
    text_string(text_string),
    size_char(size_char),
    text_color(text_color),
    hover_color(hover_color)
{
    if(!font_text.loadFromFile("res/fonts/lato/Lato-Black.ttf")){
        std::cout << "geen lato" << std::endl;
    }

    text_SFML.setFont(font_text);
    text_SFML.setPosition(position);
    text_SFML.setFillColor(text_color);
    text_SFML.setString(text_string);
    text_SFML.setCharacterSize(size_char);
    rect_SFML.setPosition(position - sf::Vector2f(text_SFML.getGlobalBounds().width*0.5, 0));
    size = {text_SFML.getGlobalBounds().width*2, float_from_double(text_SFML.getGlobalBounds().height*1.5)};
    rect_SFML.setSize(size);
    rect_SFML.setFillColor(hover_color);
}

void label::draw() {
    window.draw(rect_SFML);
    window.draw(text_SFML);
}

void label::update() {
    if(rect_SFML.getGlobalBounds().contains(vector2f_from_vector2i(sf::Mouse::getPosition()))) {
        rect_SFML.setFillColor(text_color);
        text_SFML.setFillColor(hover_color);
    }
    else{
        rect_SFML.setFillColor(hover_color);
        text_SFML.setFillColor(text_color);
    }
}
void label::update(std::string new_value) {
    text_SFML.setString(new_value);
    rect_SFML.setPosition(position - sf::Vector2f(text_SFML.getGlobalBounds().width*0.5, 0));
    size = {text_SFML.getGlobalBounds().width*2, float_from_double(text_SFML.getGlobalBounds().height*1.5)};
    rect_SFML.setSize(size);
}