#ifndef WINDOW_PART_HPP
#define WINDOW_PART_HPP
class window_part : public drawable{
protected:
    sf::RectangleShape rect;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    window_part(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, sf::Color color = sf::Color::Green):
    drawable(window, position, size){
        rect.setPosition(position);
        rect.setSize(size);
        rect.setFillColor(color);
    }
    window_part(sf::RenderWindow & window, sf::Vector2f position,std::string filename):
            drawable(window, position, {0,0}){
        rect.setSize(sf::Vector2f(0,0));
        texture.loadFromFile(filename);
        sprite.setTexture(texture);
        sprite.setPosition(position);
    }
    void draw() override{
        if(rect.getSize() == sf::Vector2f(0,0)) {
            window.draw(sprite);
        }
        else {
            window.draw(rect);
        }
    }

};

//class label : public window_part{
//private:
//    sf::Font font;
//    sf::Text txt;
//public:
//    label(sf::RenderWindow & window, sf::Vector2f position, std::string text ): window_part(window, position, sf::Vector2f(0,0)){
//        txt.setString(text);
//        if(!font.loadFromFile("res/fonts/lato/Lato-Black.ttf")){std::cout << "geen lato" << std::endl; }
//        txt.setFont(font);
//        size = sf::Vector2f(txt.getGlobalBounds().width, txt.getGlobalBounds().height);
//        txt.setCharacterSize(25);
//        txt.setPosition(sf::Vector2f(position.x + size.x *0.3, position.y));
//        rect.setSize(sf::Vector2f (size.x + size.x*0.6, size.y*1.5));
//    }
//    void draw() override{
//        window.draw(rect);
//        window.draw(txt);
//    }
//};
#endif