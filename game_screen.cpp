#include "game_screen.hpp"

#include <map>
#include <string>
#include <vector>
#include "sprite_factory.hpp"
#include "init_game.hpp"

#include "game_state_game.hpp"
#include "game_state_menu.hpp"
#include "shop.hpp"


std::vector<std::string> game_screen::init(){
    return read_values(game_setting);
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


    /// Zet een icon neer voor in de taakbalk.
    auto image = sf::Image{};
    image.loadFromFile(sprite_files_map["icon"]);
    window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

    //start state
    state_t = MENU;
    //initialisatie game
    game_state_game game(window, width, height, sprite_files_map, game_setting,  state_t);
    //Shop
    shop Shop(window, state_t, width, height, unlocked_players, sprite_files_map);

    //Menu
    game_state_menu menu_state(window, width, height,state_t,sprite_files_map,game_setting);

    while (window.isOpen()) {
        window.clear();
        switch (state_t) {
            case GAME: {
                game.draw();
                game.update();

                break;
            }
            case MENU: { // TODO Check updateables
                menu_state.draw();
                menu_state.update();
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
