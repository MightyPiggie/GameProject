#include "builder.hpp"

#include <algorithm>

#include "simple_functions.hpp"
#include "game_screen.hpp"

builder::builder(sf::RenderWindow& window, std::map<std::string , std::string> sprite_factory):
    window(window),
    sprite_factory(sprite_factory),
    rng(rd())
{start_playground();}

unsigned int builder::random_int_between_range(int min, int max) {
    std::uniform_int_distribution<int> uni(min,max);

    return uni(rng);
}

std::vector<unsigned int> builder::random_int_between_range_multiple(int min, int max, unsigned int amount) {
    std::uniform_int_distribution<int> uni(min,max);
    std::vector<unsigned int> tmp_vector;
    for(unsigned int i = 0; i <= amount; i++) {
        tmp_vector.push_back(((uni(rng))/60)*60);
    }
    std::sort( tmp_vector.begin(), tmp_vector.end() );
    tmp_vector.erase( std::unique( tmp_vector.begin(), tmp_vector.end() ), tmp_vector.end() );
    return tmp_vector;
}

void builder::update() {
    ticks +=1;
    if(ticks % 60 == 0) {
        build_underground();
    }
}

void builder::build_underground(float height, bool force_underground_grass) {
    unsigned int underground_type = random_int_between_range(0,4);
    if(underground_type == 0 && force_underground_grass == false) {
        obstacle* tmp = new obstacle {window, sf::Vector2f{width_screen/4.f, height},  sf::Vector2f{width_screen/2.f, 59.0}, NON_OBSTACLE, sprite_factory["rails_sprite"]};
        sprite_builds.push_back(tmp);
        generate_obstacle_train(height);
        generate_coins(height);
        return;
    }
    else if(underground_type == 2 && force_underground_grass == false) {  //todo WATER MUST BE CHANGED TO DEADLY
        obstacle* tmp1 = new obstacle {window, sf::Vector2f{width_screen/4.f, height},  sf::Vector2f{width_screen/2.f, 59.0}, NON_OBSTACLE, sprite_factory["roads_sprite"]};
        sprite_builds.push_back(tmp1);
        generate_obstacle_car(height);
        generate_coins(height);
        return;
    }
    else if(underground_type == 3 && force_underground_grass == false) {
        obstacle* tmp2 = new obstacle {window, sf::Vector2f{width_screen/4.f, height},  sf::Vector2f{width_screen/2.f, 59.0}, NON_OBSTACLE, sprite_factory["water_sprite"]};
        sprite_builds.push_back(tmp2);
        generate_obstacle_logs(height);
        generate_coins(height);
        return;
    }
    else if((underground_type == 1 || 4) || force_underground_grass == true) {
        obstacle* tmp3 = new obstacle {window, sf::Vector2f{width_screen/4.f, height},  sf::Vector2f{width_screen/2.f, 59.0}, NON_OBSTACLE, sprite_factory["grass_sprite"]};
        sprite_builds.push_back(tmp3);
        if(force_underground_grass == false) {
            generate_obstacle_grass(height);
            generate_coins(height);
        }
        return;
    }
}

std::vector<obstacle*> builder::return_underground_obstacles() {
    return sprite_builds;
}

std::vector<obstacle_moving*> builder::return_moving_obstacles() {
    return moving_sprite_builds;
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

    for(unsigned int i = 0; i <= location_obstacles.size(); i++) {
        unsigned int obstacle_type = random_int_between_range(0, 1);
        if(obstacle_type == 0) {
             obstacle* tmp = new obstacle {window, sf::Vector2f{((int(location_obstacles[i]/60))*60.f), height}, sf::Vector2f{59.0, 59.0}, OBSTACLE, sprite_factory["tree_sprite"]};
             sprite_builds.push_back(tmp);
            }
        else if(obstacle_type == 1) {
            obstacle* tmp = new obstacle {window, sf::Vector2f{((int(location_obstacles[i]/60))*60.f), height}, sf::Vector2f{59.0, 59.0}, OBSTACLE, sprite_factory["rock_sprite"]};
            sprite_builds.push_back(tmp);
        }
    }
}

void builder::generate_obstacle_train(float height) {
    bool direction = random_int_between_range(0, 1);
    if(direction == 0) {
        obstacle_moving* tmp = new obstacle_moving {window, sf::Vector2f{width_screen/4*3.f, height}, sf::Vector2f{240.0, 59.0}, DEADLY, sprite_factory["train_left_sprite"], 100, direction , 4};
        sprite_builds.push_back(tmp);
    }
    else if(direction == 1) {
        obstacle_moving* tmp = new obstacle_moving {window, sf::Vector2f{width_screen/4.f, height}, sf::Vector2f{240.0, 59.0}, DEADLY, sprite_factory["train_right_sprite"], 100, direction , 4};
        sprite_builds.push_back(tmp);
    }
}

void builder::generate_obstacle_car(float height) {
    bool direction = random_int_between_range(0, 1);
    int car_type = random_int_between_range(0, 4);
    if(direction == 0) {
        obstacle_moving* tmp = new obstacle_moving {window, sf::Vector2f{width_screen/4*3.f+60, height}, sf::Vector2f{59.0, 59.0}, DEADLY, sprite_factory[sprites_car[car_type*2]], 500, direction};
        sprite_builds.push_back(tmp);
    }
    else if(direction == 1) {
        obstacle_moving* tmp = new obstacle_moving {window, sf::Vector2f{width_screen/4.f-60, height}, sf::Vector2f{59.0, 59.0}, DEADLY, sprite_factory[sprites_car[car_type*2+1]], 500, direction};
        sprite_builds.push_back(tmp);
    }
}

void builder::generate_obstacle_logs(float height) {
    bool direction = random_int_between_range(0, 1);
    bool log_length = random_int_between_range(0, 1);
    if(direction == 0) {
        obstacle_moving* tmp = new obstacle_moving {window, sf::Vector2f{width_screen/4*3.f+60, height}, sf::Vector2f{119.0, 59.0}, NON_OBSTACLE, sprite_factory[sprites_log[log_length]], 300, direction};
        sprite_builds.push_back(tmp);
    }
    else if(direction == 1) {
        obstacle_moving* tmp = new obstacle_moving {window, sf::Vector2f{width_screen/4.f-60, height}, sf::Vector2f{119.0, 59.0}, NON_OBSTACLE, sprite_factory[sprites_log[log_length]], 300, direction};
        sprite_builds.push_back(tmp);
    }
}

void builder::generate_coins(float height){
    unsigned int change = random_int_between_range(0, 5);
    if(change == 0) {
        std::vector<unsigned int> location_obstacles = random_int_between_range_multiple(width_screen / 4,
                                                                                         width_screen / 4 * 3, 1);
        obstacle *tmp = new obstacle{window, sf::Vector2f{((int(location_obstacles[0] / 60)) * 60.f), height},
                                     sf::Vector2f{59.0, 59.0}, NON_OBSTACLE, sprite_factory["coin_sprite"]};
        sprite_builds.push_back(tmp);
    }
}