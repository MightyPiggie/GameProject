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
#endif