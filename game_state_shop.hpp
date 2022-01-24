#ifndef GAME_STATE_SHOP_HPP
#define GAME_STATE_SHOP_HPP
#include <SFML/Graphics.hpp>

#include "drawable.hpp"
#include "game_states.hpp"
#include "buttons.hpp"
#include "window_part.hpp"

//initialisatie shop
class game_state_shop : public drawable{
private:
    state & state_t;
    std::vector<std::string> all_players = {"chicken_sprite", "beta_player_sprite", "chicken_sprite"};
    std::vector<std::string> & unlocked_players;
    std::map<std::string, std::string> & sprite_files_map;
    std::vector<window_part> sprites;
    std::vector<drawable*> objects;
    window_part shop_window;
    buttons quit_gamewindow;
    buttons back_to_menu_from_gamewindow;
    buttons first_buy_button;
    window_part first;
    window_part second;
    window_part third;
    std::string chosen_player;
public:
    game_state_shop(sf::RenderWindow& window, state & state_t,unsigned int width,unsigned int height, std::vector<std::string> & unlocked_players, std::map<std::string, std::string> & sprite_files_map);
    void draw() override;
    void update() override;


};

#endif
