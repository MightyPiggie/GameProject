#ifndef GAME_STATE_MENU_HPP
#define GAME_STATE_MENU_HPP

#include <SFML/Graphics.hpp>

#include "drawable.hpp"


#include "simple_functions.hpp"
#include "game_states.hpp"
#include "label.hpp"
#include "buttons.hpp"
#include "window_part.hpp"
#include "sprite_factory.hpp"

class game_state_menu : public drawable{
private:
    sf::RectangleShape rect;
    unsigned int width;
    unsigned int height;
    std::map<std::string , std::string> & sprite_files_map;
    state & state_t;

    buttons quit_in_menu_window;
    buttons start_game;
    buttons shop_button_in_menu_window;

    label title_in_menu_window;

    window_part player_icon_menu_window;

    std::vector<drawable*> objects = {};
public:
    game_state_menu(sf::RenderWindow& window,
                    unsigned int width,
                    unsigned int height,
                    state & state_t,
                    std::map<std::string,std::string> & sprite_files_map);
    void draw() override;
    void update() override;
};

#endif