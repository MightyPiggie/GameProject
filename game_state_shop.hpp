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
    /// Lijst players die er zijn om hiermee de sprites ervan op te halen
    std::vector<std::string> all_players = {"chicken_shop", "slime_shop", "pacman_shop"};
    ///Lijst players die gekocht zijn?
    std::vector<std::string> & unlocked_players;
    std::map<std::string, std::string> & sprite_files_map;

    /// Lijst players die er zijn. Alles dus maar dan window_part. Met all_players kun je de juiste sprite pakken.
    std::vector<window_part*> players;
    std::vector<drawable*> objects;
    std::vector<drawable*> scrol_objects;
    window_part shop_window;
    buttons quit_gamewindow;
    buttons back_to_menu_from_gamewindow;

    /// Buttons om door de shop heen te gaan.
    buttons previeus_player_button;
    buttons buy_button;
    buttons equipe_button;
    buttons next_player_button;

    /// Players die ik heb en in de shop wil tonen
    window_part chicken;
    window_part slime;
    window_part pacman;
    std::string chosen_player;

    /// Waarde waar mee ik door de shop heen kan scrollen van players.
    unsigned int player_scrolling_int = 0;

public:
    game_state_shop(sf::RenderWindow& window, state & state_t,unsigned int width,unsigned int height, std::vector<std::string> & unlocked_players, std::map<std::string, std::string> & sprite_files_map);
    void draw() override;
    void update() override;


};

#endif
