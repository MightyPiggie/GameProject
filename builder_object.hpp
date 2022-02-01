#ifndef LINE_HPP
#define LINE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "object.hpp"

enum line_type {GRASS, RAILS, WATER, ROAD};

/// builder_object class, heritage van object
class builder_object : public object {
private:
    line_type type;
    /// Wegems refrence niet nodig.
//    std::vector<std::shared_ptr<object>> objects;
    std::vector<std::string> sprites_car = {"car_cool_left_sprite", "car_cool_right_sprite", "car_camper_left_sprite", "car_camper_right_sprite", "car_orange_left_sprite", "car_orange_right_sprite", "car_pink_left_sprite", "car_pink_right_sprite", "car_police_left_sprite", "car_police_right_sprite"};
    std::vector<std::string> sprites_log = {"tree_trunk_2t_sprite", "tree_trunk_3t_sprite"};

    /**
     * @brief The generate_coin function will have a certain change to generate a coin on the line when called.
     * 
     */
    void generate_coins();

    /**
     * @brief The generate_obstacle_car will generate a certain amount of differaint types of cars when called.
     * 
     */
    void generate_obstacle_car();

    /**
     * @brief The generate_obstacle_grass will generate a certainn amount of rocks and trees when called.
     * 
     */
    void generate_obstacle_grass();

    /**
     * @brief The generate_obstacle_train will generate a train when called.
     * 
     */
    void generate_obstacle_train();

    /**
     * @brief The generate_obstacle_logs will generate a certain amount of logs when called.
     * 
     */
    void generate_obstacle_logs();

    const unsigned int max_amount_obstacles_per_tile;

public:
    /**
     * @brief Construct a new builder object object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param position The position on which the line will be placed on.
     * @param size The size on how large a line will be.
     * @param type The type a line could be.
     * @param object_state The state a is in.
     * @param sprite_name The name of the sprite.
     */
    builder_object(sf::RenderWindow& window,
                   sf::Vector2f position,
                   sf::Vector2f size,
                   line_type type,
                   object_states object_state,
                   std::string sprite_name);

    std::vector<std::shared_ptr<object>> objects_for_level;


    /**
     * @brief The draw function will call all objects draw function and update the position of itself.
     * 
     */
    void draw() override;

    /**
     * @brief The update function will call all the objects update function.
     * 
     */
    void update() override;

    /**
     * @brief The lower function will call all objects lower function and lower the position of itself.
     * 
     */
    void lower() override;
//    std::vector<std::shared_ptr<object>> & get_objects();
};

#endif