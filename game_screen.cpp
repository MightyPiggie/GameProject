#include "game_screen.hpp"

#include <map>
#include <string>
#include <vector>
#include "sprite_factory.hpp"
#include "init_game.hpp"

#include "game_state_game.hpp"

#include "buttons.hpp"
#include "simple_functions.hpp"
#include "window_part.hpp"
#include "player.hpp"
#include "builder.hpp"
#include "menu.hpp"
#include "obstacle.hpp"
#include "shop.hpp"


std::vector<std::string> game_screen::init(){
    return read_values(coins, highscore);
}

void game_screen::run(){
    //window settingssettings
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(60);
    unlocked_players = init();

    //sprite factory
    std::ifstream sprite_file("sprite_file.txt");
    sprite_factory sprite_reader;
    std::map<std::string , std::string> sprite_files_map = sprite_reader.spritefile_read(sprite_file);

    //start state

    state_t = GAME;
    //initialisatie game
    game_state_game game(window, width, height, sprite_files_map, coins, state_t);

    //Shop
    shop Shop(window, state_t, width, height);


    while (window.isOpen()) {
        window.clear();
        switch (state_t) {
            case GAME: {

                game.draw();
                game.update();
                break;
            }
            case MENU: { // TODO Check updateables
                break;
            }
            case DEAD: {

                break;
            }
            case SHOP: {
                Shop.draw();
                Shop.update();

                break;
            }
        }
        window.display();
        sf::sleep(sf::milliseconds(20));




    }

}