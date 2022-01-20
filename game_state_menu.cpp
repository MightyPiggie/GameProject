//
// Created by Isaak van Luijk on 17/01/2022.
//

#include "game_state_menu.hpp"



//#include "game_screen.hpp" ///Moet deze wel?

game_state_menu::game_state_menu(sf::RenderWindow & window,
                                 unsigned int width,
                                 unsigned int height,
                                 state & state_t,
                                 std::map<std::string , std::string> & sprite_files_map
                                ):
                                drawable(window, {0,0}, vector2f_from_unsigned_ints(width,height)),
                                sprite_files_map(sprite_files_map),
                                state_t(state_t),
                                quit_in_menu_window(window,  50, vector2f_from_unsigned_ints(width/2 - 250, height/2 + 350),[&](){window.close();},"Quit", sf::Color(163 , 235 , 177)),
                                start_game(window, 50,  vector2f_from_unsigned_ints(width/2 - 60, height/2 + 350), [&](){state_t = GAME;},"Start", sf::Color(163 , 235 , 177)),
                                shop_button_in_menu_window(window,  50, vector2f_from_unsigned_ints(width/2 + 150, height/2 + 350),[&](){state_t = SHOP;},"Shop", sf::Color(163 , 235 , 177)),

                                title_in_menu_window(window,vector2f_from_unsigned_ints(width/2-250, height/2 - 100),"Levensmoedige vogel",60,sf::Color(163 , 235 , 177)),
                                player_icon_menu_window(window, vector2f_from_unsigned_ints(width/2 -30,height/2 + 80),sprite_files_map["chicken_sprite"])
                                {
                                rect.setSize(size);
                                rect.setPosition(0,0);
                                rect.setFillColor(sf::Color(17 , 101 , 48));

                                ///Knoppen voor de menu window //TODO FIX THIS
                                //        buttons title_in_menu_window(window, Vector2f_from_unsigned_ints(width/2-250,height/2),{210,10},
                                //                                     [](){
                                //                                         sf::SoundBuffer buffer;
                                //                                         sf::Sound sound;
                                //                                         buffer.loadFromFile("res/sounds/menu-window-title.wav");
                                //                                         sound.setBuffer(buffer);
                                //                                         std::cout << "speel geluid\n";
                                //                                         sound.play();},
                                //                                         "Levensmoedige Vogels",
                                //                                         sf::Color(163 , 235 , 177));
                                objects = {
                                        &quit_in_menu_window,
                                        &start_game,
                                        &shop_button_in_menu_window,
                                        &title_in_menu_window,
                                        &player_icon_menu_window
                                    };
                                }

void game_state_menu::draw(){
    window.draw(rect);
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