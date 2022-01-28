#include "game_screen.hpp"

#include <vector>
#include "sprite_factory.hpp"
#include "init_game.hpp"

#include "game_state_game.hpp"
#include "game_state_menu.hpp"
#include "game_state_dead.hpp"
#include "game_state_shop.hpp"

/// Laad de game_settings in van player.txt
std::vector<std::string> game_screen::init(){
    return read_values(game_setting);
}

/// Hoofd run voor de game. Vanuit de run wordt al het andere aangeroepen.
void game_screen::run(){
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

    //state in wich the game is starting
    state_t = MENU;

    //Game State
    std::shared_ptr<game_state_game> game_state;
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
                game_state->update();
                game_state->draw();
                break;
            }
            case MENU: { 
                menu_state.update();
                menu_state.draw();
                break;
            }
            case DEAD: {
                dead_state.update();
                dead_state.draw();
                break;
            }
            case RESTART :{
                game_state = std::make_shared<game_state_game>(window, width, height, game_setting,  state_t);
                game_setting.score = 0;
                game_setting.started = false;
                state_t = GAME;
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
