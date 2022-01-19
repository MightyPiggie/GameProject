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
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased

    return uni(rng);
}