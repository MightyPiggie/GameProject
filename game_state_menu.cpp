//
// Created by Isaak van Luijk on 17/01/2022.
//

#include "game_state_menu.hpp"
#include <iostream>
#include <SFML/Audio.hpp>
#include <stdlib.h>

//#include "game_screen.hpp" ///Moet deze wel?

game_state_menu::game_state_menu(sf::RenderWindow & window,
                                 unsigned int width,
                                 unsigned int height,
                                 state & state_t,
                                 std::map<std::string , std::string> & sprite_files_map
                                ):
                                drawable(window, {0,0}, vector2f_from_unsigned_ints(width,height)),
                                state_t(state_t),
                                sprite_files_map(sprite_files_map),

                                background_menu_window(window, vector2f_from_unsigned_ints(0,0),sprite_files_map["menu_background_sprite"]),
                                quit_in_menu_window(window,  50, vector2f_from_unsigned_ints(width/2 - 550, height/2 + 350),[&](){window.close();},"Quit", sf::Color(163 , 235 , 177)),
                                start_game(window, 50,  vector2f_from_unsigned_ints(width/2 - 140, height/2 + 350), [&](){state_t = GAME;},"Start", sf::Color(163 , 235 , 177)),
                                shop_button_in_menu_window(window,  50, vector2f_from_unsigned_ints(width/2 + 350, height/2 + 350),[&](){state_t = SHOP;},"Shop", sf::Color(163 , 235 , 177)),


                                title_in_menu_window(window,vector2f_from_unsigned_ints(width/2-500, height/2 - 300),"Levensmoedige vogel",60,sf::Color(163 , 235 , 177)),
                                player_icon_menu_window(window, vector2f_from_unsigned_ints(width/2 -180,height/2 - 100),sprite_files_map["chicken_sprite"])

                                {
                                    player_icon_menu_window.rescale(sf::Vector2f {5,5});


                                //TODO FIX THIS
                                objects = {
                                        &background_menu_window,
                                        &quit_in_menu_window,
                                        &start_game,
                                        &shop_button_in_menu_window,
                                        &title_in_menu_window,
                                        &player_icon_menu_window,
                                        &title_in_menu_window_sound_test
                                    };
                                }

void game_state_menu::draw(){
    for(auto &object : objects){
        object->draw();
    }
}

void game_state_menu::update(){
    for(auto &object : objects){
        object->update();
    }
    sf::Event event{};
    while (window.pollEvent(event)){}
}
