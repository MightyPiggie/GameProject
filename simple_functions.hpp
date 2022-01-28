#ifndef SIMPLEFUNCTIONS_HPP
#define SIMPLEFUNCTIONS_HPP

#include <SFML/Graphics.hpp>

/**
 * @brief 
 * 
 * @param rhs 
 * @return sf::Vector2f 
 */
sf::Vector2f vector2f_from_vector2i( sf::Vector2i rhs );

/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @return sf::Vector2f 
 */
sf::Vector2f vector2f_from_unsigned_ints(unsigned int x, unsigned int y);

/**
 * @brief 
 * 
 * @param x 
 * @return float 
 */
float float_from_double(double x);

/**
 * @brief 
 * 
 * @param rhs 
 * @return unsigned int 
 */
unsigned int unsinged_int_from_vector2f(sf::Vector2f rhs);

/**
 * @brief 
 * 
 * @param rhs 
 * @return unsigned int 
 */
unsigned int unsinged_int_from_float(float rhs);

/**
 * @brief 
 * 
 * @param min 
 * @param max 
 * @return unsigned int 
 */
unsigned int random_int_between_range(int min, int max);

/**
 * @brief 
 * 
 * @param min 
 * @param max 
 * @param amount 
 * @return std::vector<unsigned int> 
 */
std::vector<unsigned int> random_int_between_range_multiple(int min, int max, unsigned int amount);



#endif
