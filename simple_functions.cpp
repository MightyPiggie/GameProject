#include "simple_functions.hpp"

#include <random>

sf::Vector2f vector2f_from_vector2i( sf::Vector2i rhs ){
    return sf::Vector2f(
            static_cast< float >( rhs.x ),
            static_cast< float >( rhs.y )
    );
}
sf::Vector2f vector2f_from_unsigned_ints(unsigned int x, unsigned int y){
    return sf::Vector2f(
            static_cast< float >( x ),
            static_cast< float >( y )
    );
}

float float_from_double(double x){
    return static_cast<float>(x);
}

unsigned int unsinged_int_from_vector2f(sf::Vector2f rhs){
    return static_cast<unsigned int>(rhs.x);
}
unsigned int unsinged_int_from_float(float rhs){
    return static_cast<unsigned int>(rhs);
}

unsigned int random_int_between_range(int min, int max) {
    return rand() % (max+1);
}

std::vector<unsigned int> random_int_between_range_multiple(int min, int max, unsigned int amount) {
    std::vector<unsigned int> tmp_vector;
    for(unsigned int i = 0; i <= amount; i++) {
        tmp_vector.push_back(((rand() % (max+1))/60)*60);
    }
    std::sort( tmp_vector.begin(), tmp_vector.end() );
    tmp_vector.erase( std::unique( tmp_vector.begin(), tmp_vector.end() ), tmp_vector.end() );
    return tmp_vector;
}
