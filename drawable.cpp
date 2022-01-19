//
// Created by Isaak van Luijk on 17/01/2022.
//

#include "drawable.hpp"

drawable::drawable(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size):
window(window), position(position), size(size){}

//TODO Try without the =
bool drawable::within( int x, int a, int b ){
   return ( x >= a ) && ( x <= b );
}

bool drawable::overlaps(drawable* other) {
    bool x_overlap = within( 
      position.x, 
      other->position.x, 
      other->position.x + other->size.x
   ) || within( 
      other->position.x, 
      position.x, 
      position.x + size.x
   );
    bool y_overlap = within( 
      position.y, 
      other->position.y, 
      other->position.y + other->size.y
   ) || within( 
      other->position.y, 
      position.y, 
      position.y + size.y
   );
   return x_overlap && y_overlap;
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
sf::Vector2f drawable::Vector2f_from_double(double x, double y){
    return sf::Vector2f (
            static_cast<float>(x),
            static_cast<float>(y)
            );
}
float drawable::float_from_double(double x){
    return static_cast<float>(x);
}
unsigned int drawable::Unsinged_int_from_Vector2f(sf::Vector2f rhs){
    return static_cast<unsigned int>(rhs.x);
}
unsigned int drawable::unsinged_int_from_float(float rhs){
    return static_cast<unsigned int>(rhs);
}

unsigned int drawable::random_int_between_range(int min, int max) {
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased

    return uni(rng);

}

void game_drawable::lower(){
    position.y += 1;
}