#include "builder.hpp"

#include <iostream>

#include "simple_functions.hpp"

builder::builder(sf::RenderWindow& window, std::map<std::string , std::string> sprite_factory):
    window(window),
    sprite_factory(sprite_factory),
    rng(rd())
{}

unsigned int builder::random_int_between_range(int min, int max) {
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased

    return uni(rng);
}

void builder::update() {
    ticks +=1;
    if(ticks == 60) {
        build_underground();
        ticks = 0;
    }
}

void builder::build_underground() {
    unsigned int underground_type = random_int_between_range(0,4);
    std::cout << underground_type << std::endl;
    if(underground_type == 0) {
        obstacle* tmp = new obstacle {window, sf::Vector2f{float(sf::VideoMode::getDesktopMode().width)/4.f, -60.0},  sf::Vector2f{59.0, 59.0} ,NON_OBSTACLE, sprite_factory["rails_sprite"]};
        sprite_builds.push_back(tmp);
        return;
    }
    else if(underground_type == 2) {
        obstacle* tmp1 = new obstacle {window, sf::Vector2f{float(sf::VideoMode::getDesktopMode().width)/4.f, -60.0},  sf::Vector2f{59.0, 59.0} ,NON_OBSTACLE, sprite_factory["roads_sprite"]};
        sprite_builds.push_back(tmp1);
        return;
    }
    else if(underground_type == 3) {
        obstacle* tmp2 = new obstacle {window, sf::Vector2f{float(sf::VideoMode::getDesktopMode().width)/4.f, -60.0},  sf::Vector2f{59.0, 59.0} ,NON_OBSTACLE, sprite_factory["water_sprite"]};
        sprite_builds.push_back(tmp2);
        return;
    }
    else if(underground_type == 1 || 4) {
        obstacle* tmp3 = new obstacle {window, sf::Vector2f{float(sf::VideoMode::getDesktopMode().width)/4.f, -60.0},  sf::Vector2f{59.0, 59.0} ,NON_OBSTACLE, sprite_factory["grass_sprite"]};
        sprite_builds.push_back(tmp3);
    
    
    }
}

std::vector<obstacle*> builder::return_underground() {
    return sprite_builds;
}
