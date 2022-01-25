#include "game_screen.hpp"

#include <map>
#include <vector>
#include "sprite_factory.hpp"
#include "init_game.hpp"

#include "game_state_game.hpp"
#include "game_state_menu.hpp"
#include "game_state_dead.hpp"
#include "game_state_shop.hpp"


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
    state_t = GAME;
    //Game State
//    game_state_game game_state(window, width, height, sprite_files_map, game_setting,  state_t);
    game_state_game * game_state = new game_state_game(window, width, height, sprite_files_map, game_setting,  state_t);
    //Menu State
    game_state_menu menu_state(window, width, height,state_t,sprite_files_map , game_setting);

    //Dead State
    game_state_dead dead_state(window, width, height, sprite_files_map,  state_t);

    //Shop State
    game_state_shop shop_state(window, state_t, width, height , unlocked_players , sprite_files_map);



    while (window.isOpen()) {
        window.clear();
        switch (state_t) {
            case GAME: {
                game_state->update();
                game_state->draw();
                break;
            }
            case MENU: { // TODO Check updateables
                menu_state.draw();
                menu_state.update();
                break;
            }
            case DEAD: {
                dead_state.draw();
                dead_state.update();
                break;
            }
            case SHOP: {
                shop_state.draw();
                shop_state.update();
                break;
            }
        }
        window.display();
        sf::sleep(sf::milliseconds(20));




    }

}
