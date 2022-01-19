#ifndef BUILDER_HPP
#define BUILDER_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include <random>

#include "game_object.hpp"

class game_builder {
private:

public:

};

class builder : public game_object {
private:
    unsigned int ticks = 0;
    sf::RenderWindow& window;
    std::map<std::string , std::string> sprite_factory;
    std::vector<std::string> sprites = {"rails_sprite", "background_sprite", "roads_sprite", "water_sprite", "background_sprite"};
    std::vector<game_builder*> sprite_builds;
    std::random_device rd;
    std::mt19937 rng;
    
public:
    builder(sf::RenderWindow& window, std::map<std::string , std::string> sprite_factory);
    unsigned int random_int_between_range(int min, int max);
    void update() override;

};

#endif