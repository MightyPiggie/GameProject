#ifndef BUILDER_HPP
#define BUILDER_HPP
#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "sprite_factory.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include "game_object.hpp"

class game_builder {
private:


public:

};

class builder : public game_object {
private:
    unsigned int ticks = 0;
    std::map<std::string , std::string> sprite_factory;
    std::vector<std::string> sprites = {"rails_sprite", "background_sprite", "roads_sprite", "water_sprite", "background_sprite"};
    std::vector<game_builder *> sprite_builds;
public:
    builder(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, std::map<std::string , std::string> sprite_factory);
    unsigned int random_int_between_range(int min, int max);
    //void draw() override {return;};
    void update() override;

};

#endif