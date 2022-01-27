#include "line.hpp"

#include "simple_functions.hpp"

#include <iostream>

line::line(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f size, line_type type, object_states object_state, std::string sprite_name):
    object(window, position, size, object_state, sprite_name),
    type(type),
    max_amount_obstacles_per_tile(window.getSize().x/60/4)
{
    generate_coins();
    switch (type)
    {
    case GRASS:
        if(position.y <= window.getSize().y-5*60) {
            generate_obstacle_grass();
        }
        
        break;
    
    case ROAD:
        generate_obstacle_car();
        break;
    
    case RAILS:
        generate_obstacle_train();
        break;

    case WATER:
        generate_obstacle_logs();
        break;
    }
}

std::vector<std::shared_ptr<object>> line::get_objects() {
    return objects;
}

void line::update(){
    for(auto& object : objects){
        object->update();
    }
}

void line::draw(){
    sprite.setPosition(position);
    window.draw(sprite);

    for(auto& object : objects){
        object->draw();
    }
}

void line::lower(){
    position.y += 1;

    for(auto& object : objects){
        object->lower();
    }
}

void line::generate_coins(){
    unsigned int chance = random_int_between_range(0, 5);
    if(chance == 0) {
        std::vector<unsigned int> location_obstacles = random_int_between_range_multiple(window.getSize().x / 4, window.getSize().x / 4 * 3, 1);
        objects.push_back(std::make_shared<object>(window, sf::Vector2f{((int(location_obstacles[0] / 60)) * 60.f), position.y}, sf::Vector2f{59.0, 59.0}, NON_OBSTACLE, "coin_sprite"));
    }
}

void line::generate_obstacle_car() {
    bool direction = random_int_between_range(0, 1);
    int car_type = random_int_between_range(0, 4);
    auto amount_cars = random_int_between_range(3, 5);
    if(direction == 0) {
        for(unsigned int i = 0; i <= amount_cars; i++) {
            bool side = random_int_between_range(0, 1);
            objects.push_back(std::make_shared<moving_object>(window, side == 0 ? sf::Vector2f{window.getSize().x/4*3.f+60, position.y} : sf::Vector2f{float(random_int_between_range(window.getSize().x/4.f, window.getSize().x/4.f*3)) , position.y}, sf::Vector2f{59.0, 59.0}, DEADLY, sprites_car[car_type*2], 200, direction));
        }
    }
    else if(direction == 1) {
        for(unsigned int i = 0; i <= amount_cars; i++) {
            bool side = random_int_between_range(0, 1);
            objects.push_back(std::make_shared<moving_object>(window, side == 0 ? sf::Vector2f{window.getSize().x/4.f+60, position.y} : sf::Vector2f{float(random_int_between_range(window.getSize().x/4.f, window.getSize().x/4.f*3)) , position.y}, sf::Vector2f{59.0, 59.0}, DEADLY, sprites_car[car_type*2+1], 200, direction));
        }
    }
}

void line::generate_obstacle_grass() {
    unsigned int amount_obstacles = random_int_between_range(0, max_amount_obstacles_per_tile);
    std::vector<unsigned int> location_obstacles = random_int_between_range_multiple(window.getSize().x/4, window.getSize().x/4*3, amount_obstacles);

    for(unsigned int i = 0; i < location_obstacles.size(); i++) {
        unsigned int obstacle_type = random_int_between_range(0, 1);
        objects.push_back(std::make_shared<object>(window, sf::Vector2f{((int(location_obstacles[i]/60))*60.f), position.y}, sf::Vector2f{59.0, 59.0}, OBSTACLE, obstacle_type == 0 ? "tree_sprite" : "rock_sprite"));
    }
}

void line::generate_obstacle_train() {
    bool direction = random_int_between_range(0, 1);
    if(direction == 0) {
        objects.push_back(std::make_shared<moving_object>(window, sf::Vector2f{window.getSize().x/4*3.f+240, position.y}, sf::Vector2f{240.0, 59.0}, DEADLY, "train_left_sprite", 500, direction , 4));
    }
    else if(direction == 1) {
        objects.push_back(std::make_shared<moving_object>(window, sf::Vector2f{window.getSize().x/4.f-240, position.y}, sf::Vector2f{240.0, 59.0}, DEADLY, "train_right_sprite", 500, direction , 4));
    }
}

void line::generate_obstacle_logs() {
    bool direction = random_int_between_range(0, 1);
    bool log_length = random_int_between_range(0, 1);
    auto amount_logs = random_int_between_range(3, 5);
    if(direction == 0) {
        for(unsigned int i = 0; i <= amount_logs; i++) {
            bool side = random_int_between_range(0, 1);
            std::cout << side << std::endl;
            objects.push_back(std::make_shared<moving_object>(window, side == 0 ? sf::Vector2f{window.getSize().x/4*3.f+60, position.y} : sf::Vector2f{float(random_int_between_range(window.getSize().x/4.f, window.getSize().x/4.f*3)) , position.y}, log_length == 0 ? sf::Vector2f{119.0, 59.0} : sf::Vector2f{179.0, 59.0}, FLOATING, sprites_log[log_length], 200, direction));
        }
   }
    else if(direction == 1) {
        for(unsigned int i = 0; i <= amount_logs; i++) {
            bool side = random_int_between_range(0, 1);
            objects.push_back(std::make_shared<moving_object>(window, side == 0 ? sf::Vector2f{window.getSize().x/4.f-180, position.y} : sf::Vector2f{float(random_int_between_range(window.getSize().x/4.f, window.getSize().x/4.f*3)), position.y}, log_length == 0 ? sf::Vector2f{119.0, 59.0} : sf::Vector2f{179.0, 59.0}, FLOATING, sprites_log[log_length], 200, direction));
        }
    }
}