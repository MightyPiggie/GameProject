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
     * @param position A x and y coordinate for the position. this is the top left corner.
     * @param size A x and y coordinate for the size, this is the bottom right corner.
     * @param game_setting A reference to all game settings of the game.
     * @param state_t A reference to the state of the game.
     */
    player(sf::RenderWindow & window,
            sf::Vector2f position,
            sf::Vector2f size,
            game_settings & game_setting,
            state & state_t,
            sound_class & the_sound_class_player);

    /**
     * @brief This function checks for a collision on the X axis. this function is called when a left or right key is pressed.
     * 
     * @param gameobjects A reference to vector of shared pointers containing all the objects in the game.
     * @param new_position A x and y coordinate for the new position.
     */
    void function_for_move(std::vector<std::shared_ptr<builder_object>>& gameobjects, sf::Vector2f new_position);

    /**
     * @brief This function checks for a collision on the Y axis. this function is called when a up or down key is pressed. it also updates the score.
     * 
     * @param gameobjects A vector of shared pointers containing all the objects in the game.
     * @param new_position A x and y coordinate for the new position.
     * @param score A reference to the score in gamesettings
     * @param new_score_bool Checks if the score has to update.
     */
    void function_for_move_score(std::vector<std::shared_ptr<builder_object>>& gameobjects, sf::Vector2f new_position, bool & score, bool new_score_bool);

    /**
     * @brief This function draws the object on the sf::RenderWindow.
     * 
     */
    void draw() override;

    /**
     * @brief This function handles player input events
     * @details This function checks if a move is possible when a key is pressed.
     * This is not possible when the player is at the border of the window.
     * It also restores the position with the restore_position() function.
     * When the game has not started its starts the game when a key is pressed.
     * @param gameobjects A reference to a vector of shared pointers containing all the objects in the game.
     */
    void move(std::vector<std::shared_ptr<builder_object>>& gameobjects);

    /**
     * @brief This function checks if the player has died
     * @details This function checks if the player has died due to water, cars and Trains
     * It also checks if the player is not on the game screen anymore then the player dies too.
     * 
     * @param gameobjects A reference to a vector of shared pointers containing all the objects in the game.
     * @param lineobjects A reference to a shared pointer which has a builder_object with all the lines.
     */
    void check_dead(const std::vector<std::shared_ptr<object>>& gameobjects, const std::shared_ptr<builder_object>& lineobjects);

    /**
     * @brief This function returns the global bounds of this player
     * 
     * @return sf::FloatRect is a rectangle where the intersects function could be called upon.
     */
    sf::FloatRect getbounds() override;

    /**
     * @brief This funcion updates the player. This updates the sprite of the player.
     * 
     */
    void update() override;

    /**
     * @brief This function restores the position.
     * @details This function restores the position of the player to reallign it with the grid.
     * Therefor the position is rounded to the closed multiple of 60.
     */
    void restore_position();
};

#endif
