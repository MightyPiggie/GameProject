#include "game_state_loading_screen.hpp"
#include "sprite_factory.hpp"
#include "simple_functions.hpp"
#include "window_part.hpp"

game_state_loading_screen::game_state_loading_screen(sf::RenderWindow &window,
                                                     state &state_t,
                                                     sound_class &the_sound_class_loading_screen
                                                     ):
        drawable(window,{0,0},{0,0}),
        state_t(state_t),
        the_sound_class_loading_screen(the_sound_class_loading_screen)
        {
            // Zet een icon neer voor in de taakbalk.
            sprite_factory sprite_reader = sprite_factory::get_instance();
            auto image = sf::Image{};
            image.loadFromFile(sprite_reader.filenames["icon"]);
            window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

            std::shared_ptr<window_part> loading_window = std::make_shared<window_part>(window,
                                                                                     vector2f_from_unsigned_ints(0,0),
                                                                                     sprite_reader.filenames["loading_screen"]);
            objects = {loading_window};
        }

void game_state_loading_screen::draw() {
    objects[0]->draw();
}


void game_state_loading_screen::loading() {

    // Start and close window sounds
    the_sound_class_loading_screen.set_sound_buffer("window_start", "res/sounds/menu-window-title.wav");
    the_sound_class_loading_screen.set_sound_buffer("window_close", "res/sounds/windows_xp_shutdown.wav");

    // In game sounds
    the_sound_class_loading_screen.set_sound_buffer("click_sound","res/sounds/mouse_click.wav");
    the_sound_class_loading_screen.set_sound_buffer("dead","res/sounds/gtaWasted.wav");
    the_sound_class_loading_screen.set_sound_buffer("pick_up_coin", "res/sounds/pick_up_coin.wav");
    the_sound_class_loading_screen.set_sound_buffer("move_sound", "res/sounds/move_sound.wav");

    // Specific button sounds
    the_sound_class_loading_screen.set_sound_buffer("start_game","res/sounds/start_game_sound.wav");


    // Player shop sounds buffers
    the_sound_class_loading_screen.set_sound_buffer("chicken_player","res/sounds/chicken_player.wav");
    the_sound_class_loading_screen.set_sound_buffer("slime_player","res/sounds/slime_player.wav");
    the_sound_class_loading_screen.set_sound_buffer("pacman_player","res/sounds/pacman_player.wav");
    the_sound_class_loading_screen.set_sound_buffer("cow_player","res/sounds/cow_player.wav");
    the_sound_class_loading_screen.set_sound_buffer("pig_player","res/sounds/pig_player.wav");
    the_sound_class_loading_screen.set_sound_buffer("beta_player","res/sounds/beta_player.wav");


    // BackGround music's
    the_sound_class_loading_screen.set_sound_buffer("menu_background","res/sounds/menu_background_music8bit.wav");
}