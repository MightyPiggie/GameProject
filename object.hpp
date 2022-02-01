#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>

#include "drawable.hpp"
#include "game_screen.hpp"

/// object class, heritage van drawable
class object : public drawable {
protected:
    sf::RectangleShape obs;
    std::string spritename;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    /**
     * @brief Construct a new object object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param position 
     * @param size 
     * @param object_state 
     * @param spritename 
     */
    object(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, object_states object_state, std::string spritename);

    /**
     * @brief 
     * 
     */
    void draw() override;

    /**
     * @brief 
     * 
     * @return sf::FloatRect 
     */
    sf::FloatRect getbounds() override;

    /**
     * @brief 
     * 
     */
    virtual void lower();
    object_states object_state;
    virtual unsigned int get_speed(){return 0;}
    virtual bool get_direction(){return 0;}
};

/// moving_object class, heritage van object
class moving_object : public object {
protected:
    int change;
    bool direction;
    bool moving = false;
    unsigned int speed = 2;

public:
    /**
     * @brief Construct a new moving object object
     * 
     * @param window 
     * @param position 
     * @param size 
     * @param object_state 
     * @param filename 
     * @param change 
     * @param direction 
     * @param speed 
     */
    moving_object(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, object_states object_state, std::string filename, int change, bool direction , unsigned int speed = 2);
    
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
     */
    void update() override;
    unsigned int get_speed() override {return speed;}
    bool get_direction() override {return direction;}
};

#endif
