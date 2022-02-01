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
#include "builder_object.hpp"


/// player class, heritage van object
class player : public object {
protected:
    float movement_speed = 60;
    unsigned int window_width;
    unsigned int window_height;
    game_settings & game_setting;
    state & state_t;
    sound_class & the_sound_class_player;
    std::vector<std::string> unlocked_players = read_values(game_setting);
    bool overlap = false;
    sf::Sound dead;
    sf::Sound move_sound;
    sf::Sound pick_up_coin_sound;

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
            state & state_t,
            sound_class & the_sound_class_player);

    /**
     * @brief 
     * 
     * @param gameobjects 
     * @param new_position 
     */
    void function_for_move(std::vector<std::shared_ptr<builder_object>>& gameobjects, sf::Vector2f new_position);

    /**
     * @brief 
     * 
     * @param gameobjects 
     * @param new_position 
     * @param score 
     * @param new_score_bool 
     */
    void function_for_move_score(std::vector<std::shared_ptr<builder_object>>& gameobjects, sf::Vector2f new_position, bool & score, bool new_score_bool);

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
    void move(std::vector<std::shared_ptr<builder_object>>& gameobjects);

    /**
     * @brief 
     * 
     * @param gameobjects 
     * @param lineobjects 
     */
    void check_dead(const std::vector<std::shared_ptr<object>>& gameobjects, const std::shared_ptr<builder_object>& lineobjects);
//    void check_coin(std::vector<std::shared_ptr<object>>& gameobjects);

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

    /**
     * @brief 
     * 
     */
    void restore_position();
};

#endif
