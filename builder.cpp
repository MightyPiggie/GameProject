#include "builder.hpp"

#include <iostream>
#include <algorithm>
#include <unordered_set>

#include "simple_functions.hpp"

builder::builder(sf::RenderWindow& window, std::map<std::string , std::string> sprite_factory):
    window(window),
    sprite_factory(sprite_factory),
    rng(rd())
{start_playground();}

unsigned int builder::random_int_between_range(int min, int max) {
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased

    return uni(rng);
}

std::vector<unsigned int> builder::random_int_between_range_multiple(int min, int max, unsigned int amount) {
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased
    std::vector<unsigned int> tmp_vector;
    for(unsigned int i = 0; i <= amount; i++) {
        tmp_vector.push_back(uni(rng));
    }
    tmp_vector.erase( std::unique( tmp_vector.begin(), tmp_vector.end() ), tmp_vector.end() );
    return tmp_vector;
}

void builder::update() {
    ticks +=1;
    if(ticks == 60) {
        build_underground();
        ticks = 0;
    }
}

void builder::build_underground(float height, bool force_underground_grass) {
    unsigned int underground_type = random_int_between_range(0,4);
    if(underground_type == 0 && force_underground_grass == false) {
        obstacle* tmp = new obstacle {window, sf::Vector2f{width_screen/4.f, height},  sf::Vector2f{59.0, 59.0}, start_ob, NON_OBSTACLE, sprite_factory["rails_sprite"]};
        sprite_builds.push_back(tmp);
        return;
    }
    else if(underground_type == 2 && force_underground_grass == false) {
        obstacle* tmp1 = new obstacle {window, sf::Vector2f{width_screen/4.f, height},  sf::Vector2f{59.0, 59.0}, start_ob, NON_OBSTACLE, sprite_factory["roads_sprite"]};
        sprite_builds.push_back(tmp1);
        return;
    }
    else if(underground_type == 3 && force_underground_grass == false) {
        obstacle* tmp2 = new obstacle {window, sf::Vector2f{width_screen/4.f, height},  sf::Vector2f{59.0, 59.0}, start_ob, NON_OBSTACLE, sprite_factory["water_sprite"]};
        sprite_builds.push_back(tmp2);
        return;
    }
    else if((underground_type == 1 || 4) || force_underground_grass == true) {
        obstacle* tmp3 = new obstacle {window, sf::Vector2f{width_screen/4.f, height},  sf::Vector2f{59.0, 59.0}, start_ob, NON_OBSTACLE, sprite_factory["grass_sprite"]};
        sprite_builds.push_back(tmp3);
        if(force_underground_grass == false) {
            generate_obstacle_grass(height);
        }
    }
}

std::vector<obstacle*> builder::return_underground_obstacles() {
    return sprite_builds;
}

void builder::start_playground() {
    for(float i = height_screen; i >= height_screen - 4*60 ; i-=60) {
        build_underground(i, true);
    }
    for(int i = height_screen-5*60; i >= -60; i-=60) {
        build_underground(i);
    }
}

void builder::generate_obstacle_grass(float height) {
    unsigned int amount_obstacles = random_int_between_range(0, max_amount_obstacles_per_tile);
    std::vector<unsigned int> location_obstacles = random_int_between_range_multiple(width_screen/4, width_screen/4*3, amount_obstacles);
    
    for(unsigned int i = 0; i <= amount_obstacles; i++) {
        unsigned int obstacle_type = random_int_between_range(0, 1);
        if(obstacle_type == 0) {
            if(height == -60) {
                obstacle* tmp = new obstacle {window, sf::Vector2f{((int(location_obstacles[i]/60))*60.f), height}, sf::Vector2f{59.0, 59.0}, new_ob, OBSTACLE, sprite_factory["tree_sprite"]};
                sprite_builds.push_back(tmp);
            }
            else {
                obstacle* tmp = new obstacle {window, sf::Vector2f{((int(location_obstacles[i]/60))*60.f), height}, sf::Vector2f{59.0, 59.0}, start_ob, OBSTACLE, sprite_factory["tree_sprite"]};
                sprite_builds.push_back(tmp);
            }
        }
        else if(obstacle_type == 1) {
            if(height == -60) {
                obstacle* tmp = new obstacle {window, sf::Vector2f{((int(location_obstacles[i]/60))*60.f), height}, sf::Vector2f{59.0, 59.0}, new_ob, OBSTACLE, sprite_factory["rock_sprite"]};
                sprite_builds.push_back(tmp);
            }
            else {
                obstacle* tmp = new obstacle {window, sf::Vector2f{((int(location_obstacles[i]/60))*60.f), height}, sf::Vector2f{59.0, 59.0}, start_ob, OBSTACLE, sprite_factory["rock_sprite"]};
                sprite_builds.push_back(tmp);
            }
        }
    }
}