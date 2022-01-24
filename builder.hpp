#ifndef BUILDER_HPP
#define BUILDER_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include <random>
#include <vector>

#include "game_object.hpp"
#include "obstacle.hpp"

class game_builder : public obstacle{
private:

public:

};

class builder : public game_object {
private:
    unsigned int ticks = 0;
    sf::RenderWindow& window;
    std::map<std::string , std::string> sprite_factory;
    std::vector<std::string> sprites = {"rails_sprite", "grass_sprite", "roads_sprite", "water_sprite", "grass_sprite"};
    std::vector<obstacle*> sprite_builds;
    std::random_device rd;
    std::mt19937 rng;
    int height_screen = sf::VideoMode::getDesktopMode().height;
    int width_screen = sf::VideoMode::getDesktopMode().width;
    unsigned int max_amount_obstacles_per_tile = width_screen/60/4;
    void start_playground();
    void generate_obstacle_grass(float height);
    
public:
    builder(sf::RenderWindow& window, std::map<std::string , std::string> sprite_factory);
    unsigned int random_int_between_range(int min, int max);
    std::vector<unsigned int> random_int_between_range_multiple(int min, int max, unsigned int amount);
    void update() override;
    void build_underground(float height = -60.0, bool force_underground_grass = false);
    std::vector<obstacle*> return_underground_obstacles();
};

#endif