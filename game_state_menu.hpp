#ifndef GAME_STATE_MENU_HPP
#define GAME_STATE_MENU_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "drawable.hpp"
#include "simple_functions.hpp"
#include "game_states.hpp"
#include "game_settings.hpp"
#include "sound_class.hpp"

/// game_state_menu class, heritage van drawable
class game_state_menu : public drawable{
private:
    sf::RectangleShape rect;
    unsigned int width;
    unsigned int height;
    state & state_t;
    game_settings & gameSettings;
    sound_class & the_sound_class_menu;
    std::vector<std::shared_ptr<drawable>> objects = {};

    sf::Sound click_sound;

public:
    /**
     * @brief Construct a new game state menu object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param width The width of the screen.
     * @param height The height of the screen.
     * @param state_t A refence to the state of which the game is in.
     * @param gameSettings A reference to all game settings of the game.
     * @param the_sound_class_menu A reference to the sound_class object.
     */
    game_state_menu(sf::RenderWindow& window,
                    unsigned int width,
                    unsigned int height,
                    state & state_t,
                    game_settings & gameSettings,
                    sound_class & the_sound_class_menu);

    /**
     * @brief The draw function will call all objects draw function
     * 
     */
    void draw() override;

    /**
     * @brief The update function will call all the objects update function and it will poll for SFML events.
     * 
     */
    void update() override;
};

#endif
