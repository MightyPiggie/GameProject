#ifndef GAME_STATE_DEAD_HPP
#define GAME_STATE_DEAD_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "simple_functions.hpp"
#include "game_state_game.hpp"
#include "drawable.hpp"
#include "window_part.hpp"
#include "label.hpp"
#include "sprite_factory.hpp"
#include "buttons.hpp"

class game_state_dead : public drawable{
private:
    std::map<std::string , std::string> & sprite_files_map;
    state & state_t;
    window_part dead_window;
//    sf::Texture & screenshot_gamescreen;
    buttons quit_game_button;
    buttons back_to_menu_button;
    buttons restart_button;
    label dead_message;
    std::vector<drawable*> objects;
public:
    game_state_dead(sf::RenderWindow & window, unsigned int width, unsigned int height, std::map<std::string,std::string> & sprite_files_map, state & state_t);
    void draw() override;
    void update() override;
};
#endif