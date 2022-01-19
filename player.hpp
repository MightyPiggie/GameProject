#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "drawable.hpp"

class player : public game_drawable {
protected:
    const std::string filename;
    sf::Texture texture;
    sf::Sprite sprite;
    float movement_speed = 60;
    unsigned int window_width;
    unsigned int window_height;
public:
    player(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size , std::string  filename , unsigned int window_width, unsigned int window_height):
            game_drawable(window , position , size , NON_OBSTACLE) , filename(filename) , window_width(window_width), window_height(window_height)
    {}

    void draw() override;
    void move(std::vector<game_drawable *> &gameobjects);
    sf::FloatRect getbounds() override;

};


















#endif