#include "game_state_dead.hpp"

#include "window_part.hpp"
#include "label.hpp"
#include "sprite_factory.hpp"
#include "buttons.hpp"

/// game_state_dead construcor. Zet ook direct de objecten neer.
game_state_dead::game_state_dead(sf::RenderWindow & window,
                                 unsigned int width,
                                 unsigned int height,
                                 state & state_t,
                                 game_settings & gameSettings,
                                 sound_class & the_sound_class_dead
):
        drawable(window,{0,0},{0,0}),
        state_t(state_t),
        gameSettings(gameSettings),
        the_sound_class_dead(the_sound_class_dead){

        click_sound.setBuffer(the_sound_class_dead.get_sound_buffer("click_sound"));
        dead_sound.setBuffer(the_sound_class_dead.get_sound_buffer("dead"));
        sprite_factory sprite_reader = sprite_factory::get_instance();
        std::shared_ptr<window_part> dead_window = std::make_shared<window_part>(window, vector2f_from_unsigned_ints(0,0),
                                                                                 sprite_reader.filenames["game_over_background"]);
        dead_window->rescale({width/1920.f, height/1216.f});
        std::shared_ptr<buttons> quit_game_button = std::make_shared<buttons>(window,
                                                                              50,
                                                                              vector2f_from_unsigned_ints(40, 30),
                                                                              [&](){if(gameSettings.sound){click_sound.play();dead_sound.stop();}window.close();},
                                                                              "Quit",
                                                                              sf::Color(81, 81 ,81));
        std::shared_ptr<buttons> back_to_menu_button = std::make_shared<buttons>(window,
                                                                                 50,
                                                                                 vector2f_from_unsigned_ints(40, 120),
                                                                                 [&](){if(gameSettings.sound){click_sound.play();dead_sound.stop();}state_t = MENU;},
                                                                                 "Menu",
                                                                                 sf::Color(81, 81 ,81));
        std::shared_ptr<buttons> restart_button = std::make_shared<buttons>(window,
                                                                            30,
                                                                            vector2f_from_unsigned_ints(width/2 - 100, height*3/4 ),
                                                                            [&](){if(gameSettings.sound){click_sound.play(); dead_sound.stop();}state_t = RESTART;},
                                                                            "Restart",
                                                                            sf::Color(81, 81 ,81));

    objects = {dead_window , quit_game_button , back_to_menu_button ,restart_button};
}

/// Tekent de game_state_dead
void game_state_dead::draw(){
    for( auto & object : objects){
        object->draw();
    }
}

/// update de game_state_dead
void game_state_dead::update() {
    if(state_t == DEAD){
        if(dead_sound.getStatus() != sf::SoundSource::Playing){
            if(gameSettings.sound){dead_sound.play();}
        }
    }
    for(auto &object : objects){
        object->update();
    }
    sf::Event event{};
    while (window.pollEvent(event)) {}
}
