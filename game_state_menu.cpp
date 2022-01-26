//
// Created by Isaak van Luijk on 17/01/2022.
//

#include "game_state_menu.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "label_player_settings.hpp"

game_state_menu::game_state_menu(sf::RenderWindow & window,
                                 unsigned int width,
                                 unsigned int height,
                                 state & state_t,
                                 std::map<std::string , std::string> & sprite_files_map,
                                 game_settings & gameSettings
                                ):
                                drawable(window, {0,0}, vector2f_from_unsigned_ints(width,height)),
                                state_t(state_t),
                                sprite_files_map(sprite_files_map),
                                gameSettings(gameSettings)
                                {
                                std::shared_ptr<window_part> background_menu_window = std::make_shared<window_part>(window,
                                                                                     vector2f_from_unsigned_ints(0, 0),
                                                                                     sprite_files_map["menu_background_river"]);
                                std::shared_ptr<buttons> quit_in_menu_window = std::make_shared<buttons>(window,
                                                                                                         50,
                                                                                                         vector2f_from_unsigned_ints(width/2 - 550,height/2 + 350),
                                                                                                         [&](){window.close();},
                                                                                                         "Quit",
                                                                                                         sf::Color(163 , 235 , 177));
                                std::shared_ptr<buttons> start_game = std::make_shared<buttons>(window,
                                                                                                50,
                                                                                                vector2f_from_unsigned_ints(width/2 - 140, height/2 + 350),
                                                                                                [&](){state_t = GAME;},
                                                                                                "Start",
                                                                                                sf::Color(163 , 235 , 177));
                                std::shared_ptr<buttons> shop_button_in_menu_window = std::make_shared<buttons>(window,
                                                                                                                50,
                                                                                                                vector2f_from_unsigned_ints(width/2 + 350, height/2 + 350),
                                                                                                                [&](){state_t = SHOP;},
                                                                                                                "Shop",
                                                                                                                sf::Color(163 , 235 , 177));
                                std::shared_ptr<label> title_in_menu_window = std::make_shared<label>(window,
                                                                                                      vector2f_from_unsigned_ints(width/2-500, height/2 - 300),
                                                                                                      "Levensmoedige vogel",
                                                                                                      60,
                                                                                                      sf::Color(163 , 235 , 177));
                                std::shared_ptr<window_part_player> player_icon_menu_window = std::make_shared<window_part_player>(window,
                                                                                                                     vector2f_from_unsigned_ints(width/2 -200,height/2 - 100),
                                                                                                                     sprite_files_map[gameSettings.player+"_shop"],
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
                                        display_score_menu
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
