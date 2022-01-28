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
    game_state_menu(sf::RenderWindow& window,
                    unsigned int width,
                    unsigned int height,
                    state & state_t,
                    game_settings & gameSettings,
                    sound_class & the_sound_class_menu);
    void draw() override;
    void update() override;
};

#endif