//
// Created by Isaak van Luijk on 19/01/2022.
//

//#include "label.hpp"
//#include <iostream>
//
//label::label(sf::RenderWindow &window,
//             sf::Vector2f position,
//             sf::Vector2f size_rect,
//             std::string text_string,
//             int size_char,
//             sf::Color hover_color,
//             sf::Color text_color):
//        drawable(window, position, size_rect),
//        text_string(text_string),
//        size_char(size_char),
//        text_color(text_color),
//        hover_color(hover_color)
//        {
//            rect_SFML.setPosition(position);
//            rect_SFML.setSize(size);
//            rect_SFML.setFillColor(hover_color);
//            if(!font_text.loadFromFile("res/fonts/lato/Lato-Black.ttf")){
//                std::cout << "geen lato" << std::endl;
//            }
//
//            text_SFML.setFont(font_text);
//            text_SFML.setPosition(position.x,position.y);
//            text_SFML.setFillColor(text_color);
//            text_SFML.setString(text_string);
//            text_SFML.setCharacterSize(size_char);
//        }
//
//void label::draw(){
//    window.draw(rect_SFML);
//    window.draw(text_SFML);
//}
//
//void label::update(){
//    if(rect_SFML.getGlobalBounds().contains(Vector2f_from_Vector2i(sf::Mouse::getPosition()))) {
//        rect_SFML.setFillColor(text_color);
//        text_SFML.setFillColor(hover_color);
//    }
//    else{
//        rect_SFML.setFillColor(hover_color);
//        text_SFML.setFillColor(text_color);
//    }
//}