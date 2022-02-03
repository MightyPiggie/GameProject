#include "game_state_menu.hpp"

#include <SFML/Audio.hpp>
#include <iostream>

#include "label_player_settings.hpp"
#include "label.hpp"
#include "buttons.hpp"
#include "window_part.hpp"
#include "sprite_factory.hpp"
#include "game_state_loading_screen.hpp"

// Constructur van game_state_menu. Alle objecten worden er ook bij gemaakt.
game_state_menu::game_state_menu(sf::RenderWindow & window,
                                 unsigned int width,
                                 unsigned int height,
                                 state & state_t,
                                 game_settings & gameSettings,
                                 sound_class & the_sound_class_menu
                                ):
                                drawable(window, {0,0}, vector2f_from_unsigned_ints(width,height)),
                                state_t(state_t),
                                gameSettings(gameSettings),
                                the_sound_class_menu(the_sound_class_menu)
                                {
                                sprite_factory sprite_reader = sprite_factory::get_instance();

                                background_music_menu.setBuffer(the_sound_class_menu.get_sound_buffer("menu_background"));
                                background_music_menu.setVolume(25.f);
                                click_sound.setBuffer(the_sound_class_menu.get_sound_buffer("click_sound"));
                                start_button_sound.setBuffer(the_sound_class_menu.get_sound_buffer("start_game"));

                                std::shared_ptr<window_part> background_menu_window = std::make_shared<window_part>(window,
                                                                                     vector2f_from_unsigned_ints(0, 0),
                                                                                     sprite_reader.filenames["menu_background_river"]);
                                std::shared_ptr<buttons> quit_in_menu_window = std::make_shared<buttons>(window,
                                                                                                         50,
                                                                                                         vector2f_from_unsigned_ints(width/2 - 550,height/2 + 350),
                                                                                                         [&](){if(gameSettings.sound){background_music_menu.stop(); click_sound.play();} window.close();},
                                                                                                         "Quit",
                                                                                                         sf::Color(163 , 235 , 177));
                                std::shared_ptr<buttons> start_game = std::make_shared<buttons>(window,
                                                                                                50,
                                                                                                vector2f_from_unsigned_ints(width/2 - 140, height/2 + 350),
                                                                                                [&](){if(gameSettings.sound){background_music_menu.stop(); click_sound.play(); start_button_sound.play();} state_t = RESTART;},
                                                                                                "Start",
                                                                                                sf::Color(163 , 235 , 177));
                                std::shared_ptr<buttons> shop_button_in_menu_window = std::make_shared<buttons>(window,
                                                                                                                50,
                                                                                                                vector2f_from_unsigned_ints(width/2 + 350, height/2 + 350),
                                                                                                                [&](){if(gameSettings.sound){background_music_menu.stop(); click_sound.play();} state_t = SHOP;},
                                                                                                                "Shop",
                                                                                                                sf::Color(163 , 235 , 177));

                                std::shared_ptr<buttons> sound_button_in_menu_window = std::make_shared<buttons>(window,
                                                                                                                 50,
                                                                                                                 vector2f_from_unsigned_ints(25, 25),
                                                                                                                 [&](){click_sound.play(); gameSettings.sound = !gameSettings.sound;  sf::sleep(sf::milliseconds(200));},
                                                                                                                 "Sound",
                                                                                                                 sf::Color(163 , 235 , 177));



                                    std::shared_ptr<label> title_in_menu_window = std::make_shared<label>(window,
                                                                                                      vector2f_from_unsigned_ints(width/2-500, height/2 - 300),
                                                                                                      "Levensmoedige vogels",
                                                                                                      60,
                                                                                                      sf::Color(163 , 235 , 177));
                                std::shared_ptr<window_part_player> player_icon_menu_window = std::make_shared<window_part_player>(window,
                                                                                                                     vector2f_from_unsigned_ints(width/2 -200,height/2 - 100),
                                                                                                                     sprite_reader.filenames[gameSettings.player+"_shop"],
                                                                                                                     gameSettings);
                                std::shared_ptr<label_player_settings_coins> display_coins_menu = std::make_shared<label_player_settings_coins>(window,
                                                                                                    sf::Vector2f(float(width) - 250.f, 50),
                                                                                                    "Coins " + std::to_string(gameSettings.coins),
                                                                                                    25,
                                                                                                    sf::Color(163 , 235 , 177),
                                                                                                    gameSettings);
                                std::shared_ptr<label_player_settings_highscore> display_score_menu = std::make_shared<label_player_settings_highscore>(window,
                                                                                                    sf::Vector2f(float(width) - 250.f, 100),
                                                                                                    "HighS " + std::to_string(gameSettings.highscore),
                                                                                                    25,
                                                                                                    sf::Color(163 , 235 , 177),
                                                                                                    gameSettings);
                                objects = {
                                        background_menu_window,
                                        quit_in_menu_window,
                                        start_game,
                                        shop_button_in_menu_window,
                                        title_in_menu_window,
                                        player_icon_menu_window,
                                        display_coins_menu,
                                        display_score_menu,
                                        sound_button_in_menu_window
                                    };
                                }

// tekent de objecten in game_state_menu
void game_state_menu::draw(){
    for(auto &object : objects){
        object->draw();
    }
}

// update de objecten in game_state_menu
void game_state_menu::update(){
    if(state_t == MENU){
        if(gameSettings.sound){
            if (background_music_menu.getStatus() != sf::SoundSource::Playing) {
                background_music_menu.play();
            }
        }
        if(!gameSettings.sound){
            background_music_menu.stop();
        }
    }
    for(auto &object : objects){
        object->update();
    }
    sf::Event event{};
    while (window.pollEvent(event)){}
}
