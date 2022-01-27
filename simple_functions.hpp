#ifndef SIMPLEFUNCTIONS_HPP
#define SIMPLEFUNCTIONS_HPP

#include <SFML/Graphics.hpp>

sf::Vector2f vector2f_from_vector2i( sf::Vector2i rhs );
sf::Vector2f vector2f_from_unsigned_ints(unsigned int x, unsigned int y);

float float_from_double(double x);

unsigned int unsinged_int_from_vector2f(sf::Vector2f rhs);
unsigned int unsinged_int_from_float(float rhs);

unsigned int random_int_between_range(int min, int max);
std::vector<unsigned int> random_int_between_range_multiple(int min, int max, unsigned int amount);



#endif
