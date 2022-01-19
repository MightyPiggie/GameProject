//
// Created by Isaak van Luijk on 17/01/2022.
//

#include "buttons.hpp"
#include "iostream"

buttons::buttons(sf::RenderWindow &window,
                 sf::Vector2f position,
                 sf::Vector2f size,
                 std::function<void(void)> function,
                 std::string name,
                 sf::Color kleur,
                 sf::Color hover):
                 drawable(window, position, size),
                 function(function),
                 name(name),
                 kleur(kleur),
                 hover(hover){
    rect.setPosition(position);
    rect.setSize(size);
    rect.setFillColor(kleur);
    if(!font.loadFromFile("res/fonts/lato/Lato-Black.ttf")){std::cout << "geen lato" << std::endl; }
        txt.setFont(font);
        txt.setPosition({position.x, position.y});
        txt.setFillColor(hover);
        txt.setString(name);
        txt.setCharacterSize(Unsinged_int_from_Vector2f(size)/2 - Unsinged_int_from_Vector2f(size)/16);
}
void buttons::draw(){
    window.draw(rect);
    window.draw(txt);
}

void buttons::update(){
    if(rect.getGlobalBounds().contains(Vector2f_from_Vector2i(sf::Mouse::getPosition()))){
        rect.setFillColor(hover);
        txt.setFillColor(kleur);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            function();
        }
    }else{
        rect.setFillColor(kleur);
        txt.setFillColor(hover);
    }
}