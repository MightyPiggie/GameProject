#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML/Graphics.hpp>
#include <random>

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
    object(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, object_states object_state, std::string spritename);
    void draw() override;
    sf::FloatRect getbounds() override;
    virtual void lower();
    object_states object_state;
};

/// moving_object class, heritage van object
class moving_object : public object {
protected:
    int change;
    bool direction;
    bool moving = false;
    unsigned int speed = 2;

public:
    moving_object(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, object_states object_state, std::string filename, int change, bool direction , unsigned int speed = 2);
    unsigned int random_int_between_range(int min, int max);
    void update() override;
};

#endif