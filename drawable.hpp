#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>

#include "game_object.hpp"

class drawable : public game_object {
protected:
    sf::RenderWindow & window;
    sf::Vector2f position;
    sf::Vector2f size;
    //sf::Sprite image;
public:
    drawable(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size);
    bool within( int x, int a, int b );
    bool overlaps(drawable* other);
    virtual void draw()=0;
    sf::Vector2f get_position();
    sf::Vector2f get_size();
    virtual sf::FloatRect getbounds() {return sf::FloatRect{};};

};

class game_drawable : public drawable{
public:
    game_drawable(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size): drawable(window, position, size){}
    void lower(float y);
};

#endif
