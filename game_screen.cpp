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

    /// Sprite factory
    std::ifstream sprite_file("sprite_file.txt");
    sprite_factory sprite_reader = sprite_factory::get_instance();

    /// Zet een icon neer voor in de taakbalk.
    auto image = sf::Image{};
    image.loadFromFile(sprite_reader.filenames["icon"]);
    window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

    //start state
    state_t = MENU;
    //Game State
//    game_state_game game_state(window, width, height, sprite_files_map, game_setting,  state_t);
    game_state_game game_state(window, width, height, game_setting,  state_t);
    //Menu State
    game_state_menu menu_state(window, width, height,state_t, game_setting);

    //Dead State
    game_state_dead dead_state(window, width, height,  state_t);

    //Shop State
    game_state_shop shop_state(window, state_t, width, height , unlocked_players, game_setting);


    while (window.isOpen()) {
        window.clear();
        switch (state_t) {
            case GAME: {
                game_state.update();
                game_state.draw();
                break;
            }
            case MENU: { // TODO Check updateables
                menu_state.update();
                menu_state.draw();
                break;
            }
            case DEAD: {
                dead_state.update();
                dead_state.draw();
                break;
            }
            case SHOP: {
                shop_state.update();
                shop_state.draw();
                break;
            }
        }
        window.display();
        sf::sleep(sf::milliseconds(20));
    }
    save(unlocked_players,game_setting);
}
