#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

#include "drawable.hpp"
#include "init_game.hpp"
#include "game_settings.hpp"
#include "game_states.hpp"
#include "sprite_factory.hpp"
#include "object.hpp"
#include "line.hpp"


/// player class, heritage van object
class player : public object {
protected:
    float movement_speed = 60;
    unsigned int window_width;
    unsigned int window_height;
    game_settings & game_setting;
    state & state_t;
    std::vector<std::string> unlocked_players = read_values(game_setting);

public:
    /**
     * @brief Construct a new player object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param position 
     * @param size 
     * @param game_setting A reference to all game settings of the game.
     * @param state_t 
     */
    player(sf::RenderWindow & window,
            sf::Vector2f position,
            sf::Vector2f size,
            game_settings & game_setting,
            state & state_t);

    /**
     * @brief 
     * 
     */
    void draw() override;

    /**
     * @brief 
     * 
     * @param gameobjects 
     */
    void move(std::vector<std::shared_ptr<object>>& gameobjects);

    /**
     * @brief 
     * 
     * @param gameobjects 
     * @param lineobjects 
     */
    void check_dead(const std::vector<std::shared_ptr<object>>& gameobjects, const std::shared_ptr<line>& lineobjects);

    /**
     * @brief 
     * 
     * @return sf::FloatRect 
     */
    sf::FloatRect getbounds() override;

    /**
     * @brief 
     * 
     */
    void update() override;

};

#endif