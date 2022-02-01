#ifndef GAME_STATE_SHOP_HPP
#define GAME_STATE_SHOP_HPP
#include <SFML/Graphics.hpp>
#include <memory>

#include "drawable.hpp"
#include "game_states.hpp"
#include "buttons.hpp"
#include "window_part.hpp"
#include "label.hpp"
#include "game_settings.hpp"
#include <iostream>
#include "simple_functions.hpp"
#include "init_game.hpp"
#include "sound_class.hpp"

/// game_state_shop class, heritage van drawable
class game_state_shop : public drawable{
private:
    /// Game settings die erzijn
    game_settings & gameSettings;
    //state van game
    state & state_t;
    /// Lijst players die er zijn om hiermee de sprites ervan op te halen
    std::vector<std::string> all_players = {"chicken_player", "cow_player", "pig_player", "slime_player", "pacman_player" , "beta_player"};

    ///Lijst players die gekocht zijn, uit player.txt gehaald in game_screen.cpp
    std::vector<std::string> & unlocked_players;

    sound_class & the_sound_class_shop;

    /// Lijst players die er zijn. Alles dus maar dan window_part. Met all_players kun je de juiste sprite pakken.
    std::vector<std::shared_ptr<window_part>> players;
    std::vector<std::shared_ptr<drawable>> objects;
    std::shared_ptr<buttons> equip_button;
    std::shared_ptr<buttons> buy_button;
    std::shared_ptr<label> equiped_label;

    sf::Sound player_equip_sound;

    /// Waarde waar mee ik door de shop heen kan scrollen van players.
    unsigned int player_scrolling_int = 0;
    sf::Sound click_sound;

public:
    /**
     * @brief Construct a new game state shop object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param state_t A refence to the state of which the game is in.
     * @param width The width of the screen.
     * @param height The height of the screen.
     * @param unlocked_players A vector of strings containing all the player that are unlocked by the player.
     * @param gameSettings A reference to all game settings of the game.
     * @param the_sound_class_shop A reference to the sound_class object.
     */
    game_state_shop(sf::RenderWindow& window,
                    state & state_t,
                    unsigned int width,
                    unsigned int height,
                    std::vector<std::string> & unlocked_players,
                    game_settings & gameSettings,
                    sound_class & the_sound_class_shop);

    /**
     * @brief The draw function will call all objects draw function. It will also switch the button text when you buy/change a player.
     * 
     */
    void draw() override;

    /**
     * @brief The update function will call all the objects update function and it will poll for SFML events.
     * 
     */
    void update() override;

    /**
     * @brief The function checks if the selected character is unlocked by player.
     * 
     * @return true The selected character is unlocked by the player.
     * @return false The selected character is not unlocked by the player.
     */
    bool check_functie_unlocked();


};

#endif
