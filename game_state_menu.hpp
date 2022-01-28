#ifndef GAME_STATE_MENU_HPP
#define GAME_STATE_MENU_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "drawable.hpp"
#include "simple_functions.hpp"
#include "game_states.hpp"
#include "label.hpp"
#include "buttons.hpp"
#include "window_part.hpp"
#include "sprite_factory.hpp"
#include "game_settings.hpp"


/// game_state_menu class, heritage van drawable
class game_state_menu : public drawable{
private:
    sf::RectangleShape rect;
    unsigned int width;
    unsigned int height;
    state & state_t;
    game_settings & gameSettings;
    std::vector<std::shared_ptr<drawable>> objects = {};

public:
    /**
     * @brief Construct a new game state menu object
     * 
     * @param window 
     * @param width 
     * @param height 
     * @param state_t 
     * @param gameSettings 
     */
    game_state_menu(sf::RenderWindow& window,
                    unsigned int width,
                    unsigned int height,
                    state & state_t,
                    game_settings & gameSettings);

    /**
     * @brief 
     * 
     */
    void draw() override;

    /**
     * @brief 
     * 
     */
    void update() override;
};

#endif