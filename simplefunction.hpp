#ifndef SIMPLEFUNCTIONS_HPP
#define SIMPLEFUNCTIONS_HPP
sf::Vector2f Vector2f_from_Vector2i( sf::Vector2i rhs ){
    return sf::Vector2f(
            static_cast< float >( rhs.x ),
            static_cast< float >( rhs.y )
    );
}
sf::Vector2f Vector2f_from_unsigned_ints(unsigned int x, unsigned int y){
    return sf::Vector2f(
            static_cast< float >( x ),
            static_cast< float >( y )
    );
}
unsigned int Unsinged_int_from_Vector2f(sf::Vector2f rhs){
    return static_cast<unsigned int>(rhs.x);
}
unsigned int unsinged_int_from_float(float rhs){
    return static_cast<unsigned int>(rhs);
}
#endif
