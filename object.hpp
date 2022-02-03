#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>

#include "drawable.hpp"
#include "game_screen.hpp"

// object class, heritage van drawable
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
     * @param position The position where the object will the drawn on the display.
     * @param size The size of the object.
     * @param object_state The state in which the object is in.
     * @param spritename The name of the sprite that will be displayed on the screen.
     */
    object(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, object_states object_state, std::string spritename);

    /**
     * @brief The draw function will set the position and draw the object.
     * 
     */
    void draw() override;

    /**
     * @brief The getbounds function will get the global bounds of the object.
     * 
     * @return sf::FloatRect The returned FloatRect are the global bounds of the object.
     */
    sf::FloatRect getbounds() override;

    /**
     * @brief The lower function will lower the object by 1 pixel.
     * 
     */
    virtual void lower();
    object_states object_state;

    /**
     * @brief Get the speed object
     * 
     * @return unsigned int The speed a object is moving with.
     */
    virtual unsigned int get_speed(){return 0;}

    /**
     * @brief Get the direction object
     * 
     * @return true, The direction will be left.
     * @return false, The direction will be right.
     */
    virtual bool get_direction(){return 0;}
};

// moving_object class, heritage van object
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
     * @param window A reference to the window where everything is drawn on.
     * @param position The position where the object will the drawn on the display.
     * @param size The size of the object.
     * @param object_state The state in which the object is in.
     * @param filename The name of the sprite that will be displayed on the screen.
     * @param change The change a moving object has to start moving.
     * @param direction The direction a moving object will move in.
     * @param speed The speed a moving object will move in.
     */
    moving_object(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, object_states object_state, std::string filename, int change, bool direction , unsigned int speed = 2);
    
    /**
     * @brief The random_int_between_range function will give you a random integer.
     * 
     * @param min The minimum value the function can return.
     * @param max The maximum value the function can return.
     * @return unsigned int A random integeger between the minimum and maximum value.
     */
    unsigned int random_int_between_range(int min, int max);

    /**
     * @brief The update function will move the object. And if its not moving it will generate a random number between 0 and change. If its 0 the object will start moving.
     * 
     */
    void update() override;
    
    /**
    * @brief Get the speed of the object.
    *
    * @return unsigned int The speed of the object.
    */
    unsigned int get_speed() override {return speed;}
    
    /**
    * @brief Get the direction of the object.
    *
    * @return true, The direction will be left.
    * @return false, The direction will be right.
    */
    bool get_direction() override {return direction;}
};

#endif
