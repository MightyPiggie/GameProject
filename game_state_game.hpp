#ifndef GAME_STATE_GAME_HPP
#define GAME_STATE_GAME_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "drawable.hpp"
#include "window_part.hpp"
#include "player.hpp"
#include "obstacle.hpp"
#include "label.hpp"
#include "sprite_factory.hpp"
#include "buttons.hpp"
#include "builder.hpp"
#include "game_settings.hpp"
#include "label_player_settings.hpp"

class game_state_game : public drawable{
private:
    std::map<std::string , std::string> & sprite_files_map;
    game_settings & gameSettings;
    state & state_t;
    unsigned int width;
    unsigned int height;
    window_part left;
    window_part right;
    window_part game_window;
    player player1;
    label_player_settings_coins display_coins;
    label_player_settings_highscore display_highscore;
    label_player_settings_score display_score;
    buttons quit_gamewindow;
    buttons back_to_menu_gamewindow;
    builder builder1;
    std::vector<drawable*> drawables;
    std::vector<game_object*> updatables;
    std::vector<game_drawable*> game_drawables;
public:
    game_state_game(sf::RenderWindow & window,
                    unsigned int width,
                    unsigned int height,
                    std::map<std::string , std::string> & sprite_files_map,
                    game_settings & gameSettings,
                    state & state_t);
//    ~game_state_game();
    sf::Texture screenshot_gamescreen;
    void draw() override;
    void update() override;
    void destructor();
};
#endif