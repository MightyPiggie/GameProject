#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
class drawable {
protected:
    sf::RenderWindow & window;
    sf::Vector2f position;
    sf::Vector2f size;
    //sf::Sprite image;
public:
    drawable(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size);
    bool overlaps(drawable* other);
    virtual void draw()=0;
    sf::Vector2f get_position();
    sf::Vector2f get_size();
    virtual sf::FloatRect getbounds() {return sf::FloatRect{};};
    virtual void update(){}
    sf::Vector2f Vector2f_from_Vector2i( sf::Vector2i rhs );
    sf::Vector2f Vector2f_from_unsigned_ints(unsigned int x, unsigned int y);
    unsigned int Unsinged_int_from_Vector2f(sf::Vector2f rhs);
    unsigned int unsinged_int_from_float(float rhs);
};

#endif