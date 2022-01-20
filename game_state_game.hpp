#ifndef GAME_STATE_GAME_HPP
#define GAME_STATE_GAME_HPP

#include "drawable.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "window_part.hpp"
#include "player.hpp"
#include "obstacle.hpp"
#include "label.hpp"
#include "sprite_factory.hpp"
#include "buttons.hpp"

class game_state_game : public drawable{
private:
    std::map<std::string , std::string> & sprite_files_map;
    uint16_t & coins;
    state & state_t;
    window_part left;
    window_part right;
    window_part game_window;
    player player1;
    obstacle test1;
    obstacle road1;
    label display_coins;
    buttons quit_gamewindow;
    buttons back_to_menu_gamewindow;
    std::vector<drawable *> drawables;
    std::vector<game_drawable *> game_drawables;
public:
    game_state_game(sf::RenderWindow & window, unsigned int width, unsigned int height, std::map<std::string , std::string> & sprite_files_map, uint16_t & coins, state & state_t);
    void draw() override;
    void update() override;
};
#endif