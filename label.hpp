//
// Created by Isaak van Luijk on 19/01/2022.
//

#ifndef LABEL_HPP
#define LABEL_HPP



class label : public drawable{
protected:
    std::string text_string;
    int size_char;
    sf::Color text_color;
    sf::Color hover_color;

    sf::RectangleShape rect_SFML;
    sf::Font font_text;
    sf::Text text_SFML;
public:
    label(sf::RenderWindow &window,
          sf::Vector2f position,
          //sf::Vector2f size_rect,
          std::string text_string,
          int size_char,
          sf::Color hover_color,
          sf::Color text_color = sf::Color::Black):
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
        size = {text_SFML.getGlobalBounds().width*2, static_cast<float>(text_SFML.getGlobalBounds().height*1.5)};
        rect_SFML.setSize(size);
        rect_SFML.setFillColor(hover_color);
    }

    void draw() override{
        window.draw(rect_SFML);
        window.draw(text_SFML);
    }

    void update() override{
        if(rect_SFML.getGlobalBounds().contains(Vector2f_from_Vector2i(sf::Mouse::getPosition()))) {
            rect_SFML.setFillColor(text_color);
            text_SFML.setFillColor(hover_color);
        }
        else{
            rect_SFML.setFillColor(hover_color);
            text_SFML.setFillColor(text_color);
        }
    }
};


#endif