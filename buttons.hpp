#ifndef BUTTONS_HPP
#define BUTTONS_HPP

class buttons : public drawable{
private:
    sf::RectangleShape rect;
    sf::Color kleur;
    sf::Color hover;
    sf::Font font;
    sf::Text txt;
public:
    buttons(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f size, sf::Color kleur, sf::Color hover = sf::Color::Black): drawable(window, position, size), kleur(kleur), hover(hover){
        rect.setPosition(position);
        rect.setSize(size);
        rect.setFillColor(kleur);
        if(!font.loadFromFile("res/fonts/lato/Lato-Black.ttf")){std::cout << "geen lato" << std::endl; }
        txt.setFont(font);
        txt.setPosition({position.x + 5, position.y});
        txt.setFillColor(hover);
        txt.setString("Quit");
        txt.setCharacterSize(Unsinged_int_from_Vector2f(size)/2 - Unsinged_int_from_Vector2f(size)/16);
    }
    void draw() override{
        window.draw(rect);
        window.draw(txt);
    }
    void update() override{
        if(rect.getGlobalBounds().contains(Vector2f_from_Vector2i(sf::Mouse::getPosition()))){
            rect.setFillColor(hover);
            txt.setFillColor(kleur);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                window.close();
            }
        }else{
            rect.setFillColor(kleur);
            txt.setFillColor(hover);
        }
    }
};
#endif