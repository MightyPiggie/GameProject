#include "label.hpp"

#include <iostream>

#include "simple_functions.hpp"

label::label(sf::RenderWindow &window,
        sf::Vector2f position,
        std::string text_string,
        int size_char,
        sf::Color background_text_color,
        bool rectangle_display,
        sf::Color text_color):
    drawable(window, position, {0,0}),
    text_string(text_string),
    size_char(size_char),
    rectangle_display(rectangle_display),
    text_color(text_color),
    background_text_color(background_text_color)
{
    if(!font_text.loadFromFile("res/fonts/arcade_font.ttf")){
        std::cout << "geen arcade_font" << std::endl;
    }

    text_SFML.setFont(font_text);
    text_SFML.setPosition(position);
    text_SFML.setFillColor(text_color);
    text_SFML.setString(text_string);
    text_SFML.setFillColor(text_color);
    text_SFML.setCharacterSize(size_char);
    rect_SFML.setPosition(position - sf::Vector2f(float_from_double(text_SFML.getGlobalBounds().width*0.3), 0));
    size ={ float_from_double(text_SFML.getGlobalBounds().width*1.6), float_from_double(text_SFML.getGlobalBounds().height*1.5)};
    rect_SFML.setSize(size);
    rect_SFML.setFillColor(background_text_color);
}

void label::draw() {
    if(rectangle_display){
         window.draw(rect_SFML);
    }
    window.draw(text_SFML);
}

void label::update_text(std::string new_value) {
    text_SFML.setString(new_value);
    rect_SFML.setPosition(position - sf::Vector2f(float_from_double(text_SFML.getGlobalBounds().width*0.3), 0));
    size ={ float_from_double(text_SFML.getGlobalBounds().width*1.6), float_from_double(text_SFML.getGlobalBounds().height*1.5)};
    rect_SFML.setSize(size);
}