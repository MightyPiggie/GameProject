#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "drawable.hpp"
#include <iostream>

class player : public game_drawable {
protected:
    const std::string filename;
    sf::Texture texture;
    sf::Sprite sprite;
    float movement_speed = 60;
    unsigned int window_width;
    unsigned int window_height;
    uint16_t & score;
public:
    player(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, shitty_fix_enum state_t, std::string  filename , unsigned int window_width, unsigned int window_height, uint16_t & score):
            game_drawable(window, position, size, state_t, NON_OBSTACLE),
            filename(filename),
            window_width(window_width),
            window_height(window_height),
            score(score)
    {}

    void draw() override;
    void move(std::vector<game_drawable*> &gameobjects);
    sf::FloatRect getbounds() override;

};

#endif