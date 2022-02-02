#include "buttons.hpp"

#include <iostream>

#include "simple_functions.hpp"

/// Buttons constructor. Zorgt er ook direct voor dat de button wordt getekend.
buttons::buttons(sf::RenderWindow &window,
                 int char_size,
                 sf::Vector2f position,
                 std::function<void(void)> function,
                 std::string name,
                 sf::Color color_button,
                 sf::Color hover):
drawable(window, position, {0,0}),
function(function),
name(name),
color_button(color_button),
hover(hover), 
char_size(char_size){

    if(!font.loadFromFile("res/fonts/arcade_font.ttf")){std::cout << "geen arcade_font" << std::endl; }
    txt.setFont(font);
    txt.setPosition(position);
    txt.setFillColor(hover);
    txt.setString(name);
    txt.setCharacterSize(char_size);
    rect.setPosition(position - sf::Vector2f(float_from_double(txt.getGlobalBounds().width*0.3), 0));
    size ={ float_from_double(txt.getGlobalBounds().width*1.6), float_from_double(txt.getGlobalBounds().height*1.5)};
    rect.setSize(size);
    rect.setFillColor(color_button);
}


/// Tekent de button.
void buttons::draw(){
    window.draw(rect);
    window.draw(txt);
}

/// Update button. Kijkt of de muis erop zit. Of er op de klikt wordt. Hierop reacties.
void buttons::update(){
    if(rect.getGlobalBounds().contains(vector2f_from_vector2i(sf::Mouse::getPosition()))){
        rect.setFillColor(hover);
        txt.setFillColor(color_button);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            function();
        }
    }else{
        rect.setFillColor(color_button);
        txt.setFillColor(hover);
    }
}
