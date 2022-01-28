#ifndef LINE_HPP
#define LINE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "object.hpp"

enum line_type {GRASS, RAILS, WATER, ROAD};

/// line class, heritage van object
class line : public object {
private:
    line_type type;
    /// Wegems refrence niet nodig.
//    std::vector<std::shared_ptr<object>> objects;
    std::vector<std::string> sprites_car = {"car_cool_left_sprite", "car_cool_right_sprite", "car_camper_left_sprite", "car_camper_right_sprite", "car_orange_left_sprite", "car_orange_right_sprite", "car_pink_left_sprite", "car_pink_right_sprite", "car_police_left_sprite", "car_police_right_sprite"};
    std::vector<std::string> sprites_log = {"tree_trunk_2t_sprite", "tree_trunk_3t_sprite"};

    void generate_coins();
    void generate_obstacle_car();
    void generate_obstacle_grass();
    void generate_obstacle_train();
    void generate_obstacle_logs();

    const unsigned int max_amount_obstacles_per_tile;

public:
    line(sf::RenderWindow& window,
            sf::Vector2f position,
            sf::Vector2f size,
            line_type type,
            object_states object_state,
            std::string sprite_name);

    std::vector<std::shared_ptr<object>>  objects_for_level;

    void draw() override;
    void update() override;
//    void lower_obstakels();
    void lower() override;
};

#endif