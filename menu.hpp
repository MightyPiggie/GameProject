#ifndef MENU_HPP
#define MENU_HPP

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