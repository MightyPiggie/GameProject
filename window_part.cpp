#include "window_part.hpp"

window_part::window_part(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f size, sf::Color color):
    drawable(window, position, size)
{
    rect.setPosition(position);
    rect.setSize(size);
    rect.setFillColor(color);
}

window_part::window_part(
        sf::RenderWindow& window, sf::Vector2f position,std::string filename):
    drawable(window, position, {0,0})
{
    rect.setSize(sf::Vector2f(0,0));
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void window_part::draw(){
    if(rect.getSize() == sf::Vector2f(0,0)) {
        window.draw(sprite);
    }
    else {
        window.draw(rect);
    }
}