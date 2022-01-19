
#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include "gamestates.hpp"
#include <iostream>
#include <random>

class drawable {
protected:
    sf::RenderWindow & window;
    sf::Vector2f position;
    sf::Vector2f size;
public:
    drawable(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size);
    bool within( int x, int a, int b );
    bool overlaps(drawable* other);
    virtual void draw()=0;
    sf::Vector2f get_position();
    sf::Vector2f get_size();
    virtual sf::FloatRect getbounds() {return sf::FloatRect{};};

    virtual void update(){}
sf::Vector2f Vector2f_from_Vector2i( sf::Vector2i rhs );
sf::Vector2f Vector2f_from_unsigned_ints(unsigned int x, unsigned int y);
sf::Vector2f Vector2f_from_double(double x, double y);
float float_from_double(double x);
unsigned int Unsinged_int_from_Vector2f(sf::Vector2f rhs);
unsigned int unsinged_int_from_float(float rhs);

unsigned int random_int_between_range(int min, int max) ;
};

class game_drawable : public drawable{
public:
    game_drawable(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size , object_states object_state):
        drawable(window, position, size) , object_state(object_state)
        {}
    object_states object_state;
    void lower();
};

#endif
