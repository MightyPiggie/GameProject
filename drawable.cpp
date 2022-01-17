//
// Created by Isaak van Luijk on 17/01/2022.
//

#include "drawable.hpp"

drawable::drawable(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size):
window(window), position(position), size(size){}
bool drawable::overlaps(drawable* other) {
    return getbounds().intersects(other->getbounds()); 
}
//virtual void drawable::draw()=0;

sf::Vector2f drawable::get_position(){return position;}

sf::Vector2f drawable::get_size(){return size;}

//virtual void drawable::update(){}

sf::Vector2f drawable::Vector2f_from_Vector2i( sf::Vector2i rhs ){
    return sf::Vector2f(
            static_cast< float >( rhs.x ),
            static_cast< float >( rhs.y )
    );
}
sf::Vector2f drawable::Vector2f_from_unsigned_ints(unsigned int x, unsigned int y){
    return sf::Vector2f(
            static_cast< float >( x ),
            static_cast< float >( y )
    );
}
unsigned int drawable::Unsinged_int_from_Vector2f(sf::Vector2f rhs){
    return static_cast<unsigned int>(rhs.x);
}
unsigned int drawable::unsinged_int_from_float(float rhs){
    return static_cast<unsigned int>(rhs);
}
void game_drawable::lower(float y){
    position.y += y;
}