#ifndef SIMPLE_FUNCTIONS_HPP
#define SIMPLE_FUNCTIONS_HPP

#include <SFML/Graphics.hpp>

/**
 * @brief This function converts a vector2i to a vector2f
 * 
 * @param rhs a vector2i containing a integer x and integer y
 * @return sf::Vector2f containing a float x and float y
 */
sf::Vector2f vector2f_from_vector2i( sf::Vector2i rhs );

/**
 * @brief this function combines to unsigned integers to a vector 2f
 * 
 * @param x unsigned integer x
 * @param y unsigned integer y
 * @return sf::Vector2f containing a float x and float y
 */
sf::Vector2f vector2f_from_unsigned_ints(unsigned int x, unsigned int y);

/**
 * @brief this function returns a float from a double.
 * 
 * @param x double
 * @return float 
 */
float float_from_double(double x);

/**
 * @brief This function returns the X value as unsigned int from the vector2f
 * 
 * @param rhs contains a float x and float y
 * @return unsigned int x from the rhs.
 */
unsigned int unsinged_int_from_vector2f(sf::Vector2f rhs);

/**
 * @brief This function converts a float to an unsinged int
 * 
 * @param rhs float
 * @return unsigned int 
 */
unsigned int unsinged_int_from_float(float rhs);

/**
 * @brief This function returns a random int between a range.
 * 
 * @param min is the minimal integer
 * @param max is the maximal integer
 * @return unsigned int a random integer between the min and max
 */
unsigned int random_int_between_range(int min, int max);

/**
 * @brief This function returns a vector filled with random unsigned ints
 * 
 * @param min minimal integer range
 * @param max maximal integer range
 * @param amount the amount of unsigned ints in the vector
 * @return std::vector<unsigned int> a vector with unsigned ints.
 */
std::vector<unsigned int> random_int_between_range_multiple(int min, int max, unsigned int amount);

#endif
