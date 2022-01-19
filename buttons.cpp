//
// Created by Isaak van Luijk on 17/01/2022.
//

#include "buttons.hpp"
#include "iostream"
#include "simplefunction.hpp"

buttons::buttons(sf::RenderWindow &window,
                 int char_size,
                 sf::Vector2f position,
                 std::function<void(void)> function,
                 std::string name,
                 sf::Color kleur,
                 sf::Color hover):
                 drawable(window, position, {0,0}),
                 function(function),
                 name(name),
                 kleur(kleur),
                 hover(hover), char_size(char_size){

    if(!font.loadFromFile("res/fonts/lato/Lato-Black.ttf")){std::cout << "geen lato" << std::endl; }
    txt.setFont(font);
    txt.setPosition(position);
    txt.setFillColor(hover);
    txt.setString(name);
    txt.setCharacterSize(char_size);
    rect.setPosition(position - sf::Vector2f(float_from_double(txt.getGlobalBounds().width*0.3), 0));
    size ={ float_from_double(txt.getGlobalBounds().width*1.6), float_from_double(txt.getGlobalBounds().height*1.5)};
    rect.setSize(size);
    rect.setFillColor(kleur);
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