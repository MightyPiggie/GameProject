#ifndef MENU_HPP
#define MENU_HPP

class startbutton : public buttons{
    state & state_t;
public:
    startbutton(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, state & state_t, sf::Color kleur, sf::Color hover = sf::Color::Black): buttons(window, position, size, kleur, hover), state_t(state_t){
        txt.setString("start");
    }
    void update() override{
        if(rect.getGlobalBounds().contains(Vector2f_from_Vector2i(sf::Mouse::getPosition()))){
            rect.setFillColor(hover);
            txt.setFillColor(kleur);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                state_t = GAME;
            }
        }else{
            rect.setFillColor(kleur);
            txt.setFillColor(hover);
        }
    }
};

class back_to_menu_button : public buttons{
    state & state_t;
public:
    back_to_menu_button(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, state & state_t, sf::Color kleur, sf::Color hover = sf::Color::Black): buttons(window, position, size, kleur, hover), state_t(state_t){
        txt.setString("Menu");
        rect.setPosition({position.x + position.x/2, position.y});
    }
    void update() override{
        if(rect.getGlobalBounds().contains(Vector2f_from_Vector2i(sf::Mouse::getPosition()))){
            rect.setFillColor(hover);
            txt.setFillColor(kleur);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                state_t = MENU;
            }
        }else{
            rect.setFillColor(kleur);
            txt.setFillColor(hover);
        }
    }
};
class menu : public drawable{
private:
    sf::RectangleShape rect;
public:
    menu(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size): drawable(window, position, size){
        rect.setSize(size);
        rect.setPosition(0,0);
        rect.setFillColor(sf::Color::Blue);
    }
    void draw() override{
        window.draw(rect);
    }
};
#endif