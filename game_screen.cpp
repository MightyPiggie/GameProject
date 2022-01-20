#include "game_screen.hpp"

//#include <fstream>
#include <map>
#include <string>
#include <vector>

#include "sprite_factory.hpp"
#include "init_game.hpp"
#include "game_state_game.hpp"

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


    while (window.isOpen()) {
        window.clear();
        switch (state_t) {
            case GAME: {
                game.draw();
                game.update();
                break;
            }
            case MENU: { // TODO Check updateables

            }
            case DEAD: {

                break;
            }
            case SHOP: {

                break;
            }
        }
        window.display();
        sf::sleep(sf::milliseconds(20));




    }

}