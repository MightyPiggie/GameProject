#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "game_states.hpp"

/// Drawable class. Superclass voor elk object?
class drawable {
protected:
    sf::RenderWindow & window;
    sf::Vector2f position;
    sf::Vector2f size;
public:
    /**
     * @brief Construct a new drawable object
     * 
     * @param window 
     * @param position 
     * @param size 
     */
    drawable(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size);

    /**
     * @brief 
     * 
     * @param x 
     * @param a 
     * @param b 
     * @return true 
     * @return false 
     */
    bool within( int x, int a, int b );

    /**
     * @brief 
     * 
     * @param other 
     * @return true 
     * @return false 
     */
    bool overlaps(std::shared_ptr<drawable> other);

    /**
     * @brief 
     * 
     */
    virtual void draw()=0;

    /**
     * @brief 
     * 
     */
    virtual void update(){}

    /**
     * @brief Get the position object
     * 
     * @return sf::Vector2f 
     */
    sf::Vector2f get_position();

    /**
     * @brief Get the size object
     * 
     * @return sf::Vector2f 
     */
    sf::Vector2f get_size();

    /**
     * @brief 
     * 
     * @return sf::FloatRect 
     */
    virtual sf::FloatRect getbounds() {return sf::FloatRect{};};
};

#endif
