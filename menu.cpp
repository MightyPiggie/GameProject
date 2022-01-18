//
// Created by Isaak van Luijk on 17/01/2022.
//

#include "menu.hpp"


menu::menu(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size): drawable(window, position, size){
    rect.setSize(size);
    rect.setPosition(0,0);
    rect.setFillColor(sf::Color(17 , 101 , 48));
}
void menu::draw(){
window.draw(rect);
}