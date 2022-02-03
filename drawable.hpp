#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "game_states.hpp"

// Drawable class. Superclass voor bijna alle objecten.
class drawable {
protected:
    sf::RenderWindow & window;
    sf::Vector2f position;
    sf::Vector2f size;
public:
    /**
     * @brief Construct a new drawable object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param position The position where the drawable will be on the screen.
     * @param size The size of the drawable.
     */
    drawable(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size);

    /**
     * @brief The within function checks of the given integers are within each other
     * 
     * @param x The first integer to check with if its within.
     * @param a The second integer to check with if its within.
     * @param b The third integer to check with if its within.
     * @return true The other object overlaps with the this object.
     * @return false The other object does not overlap with the this object.
     */
    bool within( int x, int a, int b );

    /**
     * @brief check if the other drawable overlaps with the "this" drawable.
     * 
     * @param other The drawable to check with if it is overlaping
     * @return true If it overlaps
     * @return false If it does not overlap.
     */
    bool overlaps(std::shared_ptr<drawable> other);

    /**
     * @brief A virtual draw function. This function should every child implement so the object can be drawed on the screen.
     * 
     */
    virtual void draw()=0;

    /**
     * @brief A virtual update function. This function can be implemented in the childs if it needs to be updated.
     * 
     */
    virtual void update(){}

    /**
     * @brief Get the position of the object
     * 
     * @return sf::Vector2f 
     */
    sf::Vector2f get_position();

    /**
     * @brief Get the size of the object
     * 
     * @return sf::Vector2f 
     */
    sf::Vector2f get_size();

    /**
     * @brief Get the global bounds of the object.
     * 
     * @return sf::FloatRect 
     */
    virtual sf::FloatRect getbounds() {return sf::FloatRect{};};
};

#endif
