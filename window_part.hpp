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
    void draw() override{
        window.draw(rect);
    }

    void spritedraw(std::string  filename){
        texture.loadFromFile(filename);
        sprite.setTexture(texture);
        sprite.setPosition(position);
        window.draw(sprite);
    }
};


#endif