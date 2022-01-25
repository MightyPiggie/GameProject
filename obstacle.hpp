#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <SFML/Graphics.hpp>
#include <random>

#include "drawable.hpp"
#include "game_screen.hpp"
#include "player.hpp"

class obstacle : public game_drawable {
private:
    sf::RectangleShape obs;
    const std::string filename;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    obstacle(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, object_states object_state, std::string filename);
    void draw() override;
    sf::FloatRect getbounds() override;
};

class obstacle_moving : public obstacle {
protected:
    int change;
    bool direction;
    bool moving;
    std::random_device rd;
    std::mt19937 rng;
public:
    obstacle_moving(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, object_states object_state, std::string filename, int change, bool direction);
    unsigned int random_int_between_range(int min, int max);
    void update() override;
};

#endif