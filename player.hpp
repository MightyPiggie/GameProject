#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "drawable.hpp"
#include "game_settings.hpp"
#include "game_states.hpp"
#include <iostream>

class player : public game_drawable {
protected:
    const std::string filename;
    sf::Texture texture;
    sf::Sprite sprite;
    float movement_speed = 60;
    unsigned int window_width;
    unsigned int window_height;
    game_settings & game_setting;
    state & state_t;
public:
    player(sf::RenderWindow & window,
           sf::Vector2f position,
           sf::Vector2f size,
           std::string  filename ,
           unsigned int window_width,
           unsigned int window_height,
           game_settings & game_setting,
           state & state_t):
            game_drawable(window, position, size, NON_OBSTACLE),
            filename(filename),
            window_width(window_width),
            window_height(window_height),
            game_setting(game_setting),
            state_t(state_t)
    {}

    void draw() override;
    void move(std::vector<game_drawable*> &gameobjects);
    void check_dead(std::vector<game_drawable*> &gameobjects);
    sf::FloatRect getbounds() override;

};

#endif