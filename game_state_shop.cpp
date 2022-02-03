#include "game_state_shop.hpp"
#include "label_player_settings.hpp"

#include "sprite_factory.hpp"

game_state_shop::game_state_shop(sf::RenderWindow& window,
                                 state & state_t,
                                 unsigned int width,
                                 unsigned int height,
                                 std::vector<std::string> & unlocked_players,
                                 game_settings & gameSettings,
                                 sound_class & the_sound_class_shop
                                 ):
                                 drawable(window,{0,0}, {0,0}),
                                 gameSettings(gameSettings),
                                 state_t(state_t),
                                 unlocked_players(unlocked_players),
                                 the_sound_class_shop(the_sound_class_shop)
                                {
                                    click_sound.setBuffer(the_sound_class_shop.get_sound_buffer("click_sound"));
                                    sprite_factory sprite_reader = sprite_factory::get_instance();
                                    std::shared_ptr<window_part> shop_window = std::make_shared<window_part>(window,
                                                                                                             vector2f_from_unsigned_ints(0,0),
                                                                                                             sprite_reader.filenames["shop"]);
                                    shop_window->rescale({width/1023.f, height/665.f});
                                    std::shared_ptr<buttons> quit_gamewindow = std::make_shared<buttons>(window,
                                                                                                         50,
                                                                                                         vector2f_from_unsigned_ints(60,30),
                                                                                                         [&](){if(gameSettings.sound){click_sound.play();player_equip_sound.stop();} save(unlocked_players, gameSettings) ;window.close();},
                                                                                                         "Quit",
                                                                                                         sf::Color(163 , 235 , 177));
                                    std::shared_ptr<buttons> back_to_menu_from_gamewindow = std::make_shared<buttons>(window,
                                                                                                                      50,
                                                                                                                      vector2f_from_unsigned_ints(60, 120),
                                                                                                                      [&](){if(gameSettings.sound){click_sound.play();player_equip_sound.stop();} save(unlocked_players, gameSettings); state_t = MENU;},
                                                                                                                      "Menu",
                                                                                                                      sf::Color(163 , 235 , 177));
                                    std::shared_ptr<label_player_settings_coins> display_coins_shop = std::make_shared<label_player_settings_coins>(window,
                                                                                                                                                    sf::Vector2f(float(width) - 250.f, 50),
                                                                                                                                                    "Coins " + std::to_string(gameSettings.coins),
                                                                                                                                                    25,
                                                                                                                                                    sf::Color(163 , 235 , 177),
                                                                                                                                                    gameSettings);
                                            // Shop buttons
                                    std::shared_ptr<buttons> previeus_player_button = std::make_shared<buttons>(window,
                                                                                                                50,
                                                                                                                vector2f_from_unsigned_ints(width/10.f, height - 200.f),
                                                                                                                [&](){if(gameSettings.sound){click_sound.play();}if(player_scrolling_int <= 0){
                                                                                                                    player_scrolling_int = players.size()-1;
                                                                                                                }
                                                                                                                else{player_scrolling_int--;
                                                                                                                }
                                                                                                                sf::sleep(sf::milliseconds(200));
                                                                                                                },
                                                                                                                "prev",
                                                                                                                sf::Color(163 , 235 , 177));
                                    std::shared_ptr<buttons> buy = std::make_shared<buttons>(window,
                                                                                                    50,
                                                                                                    vector2f_from_unsigned_ints(width/3 - 110, height - 200),
                                                                                                    [&](){if(gameSettings.sound){click_sound.play();} if(gameSettings.coins >= 100){
                                                                                                        unlocked_players.push_back(all_players[player_scrolling_int]);
                                                                                                        gameSettings.coins -= 100;
                                                                                                    }
                                                                                                        sf::sleep(sf::milliseconds(200));
                                                                                                        },
                                                                                                        "Buy 100",
                                                                                                        sf::Color(163 , 235 , 177));
                                    std::shared_ptr<buttons> equip = std::make_shared<buttons>(window,
                                                                                                      50,
                                                                                                      vector2f_from_unsigned_ints(width/3 - 80, height - 200),
                                                                                                      [&](){if(gameSettings.sound){click_sound.play();
                                        player_equip_sound.setBuffer(the_sound_class_shop.get_sound_buffer(all_players[player_scrolling_int]));
                                        player_equip_sound.play();}
                                        gameSettings.player = all_players[player_scrolling_int];
                                                                                                        sf::sleep(sf::milliseconds(200));
                                                                                                        },
                                                                                                        "Equip",
                                                                                                        sf::Color(163 , 235 , 177));
                                    std::shared_ptr<label> equipped = std::make_shared<label>(window,
                                                                                                     vector2f_from_unsigned_ints(width/3 - 150, height - 200),
                                                                                                     "Equipped",
                                                                                                        50,
                                                                                                     sf::Color(163 , 235 , 177));
                                    std::shared_ptr<buttons> next_player_button = std::make_shared<buttons>(window,
                                                                                                            50,
                                                                                                            vector2f_from_unsigned_ints(width/2,height - 200),
                                                                                                            [&](){if(gameSettings.sound){click_sound.play();} if(player_scrolling_int >= players.size()-1){
                                                                                                                player_scrolling_int = 0;
                                                                                                            }
                                                                                                            else{player_scrolling_int++;
                                                                                                            }
                                                                                                            sf::sleep(sf::milliseconds(200));
                                                                                                            },
                                                                                                            "next",
                                                                                                            sf::Color(163 , 235 , 177));

                                    //Steeds players toevoegen aan deze lijst. Deze komen in een vector. Door deze loop je steeds
                                    sf::Vector2f player_layout_position = vector2f_from_unsigned_ints(width/3 - 180,  400);
                                    std::shared_ptr<window_part> chicken = std::make_shared<window_part>(window, player_layout_position, sprite_reader.filenames[all_players[0]+"_shop"]);
                                    std::shared_ptr<window_part> cow = std::make_shared<window_part>(window, player_layout_position, sprite_reader.filenames[all_players[1]+"_shop"]);
                                    std::shared_ptr<window_part> pig = std::make_shared<window_part>(window, player_layout_position, sprite_reader.filenames[all_players[2]+"_shop"]);
                                    std::shared_ptr<window_part> slime = std::make_shared<window_part>(window, player_layout_position, sprite_reader.filenames[all_players[3]+"_shop"]);
                                    std::shared_ptr<window_part> pacman = std::make_shared<window_part>(window, player_layout_position, sprite_reader.filenames[all_players[4]+"_shop"]);
                                    std::shared_ptr<window_part> beta_player = std::make_shared<window_part>(window, player_layout_position, sprite_reader.filenames[all_players[5]+"_shop"]);

                                    objects = {shop_window,quit_gamewindow,back_to_menu_from_gamewindow, previeus_player_button, next_player_button, display_coins_shop};
                                    players = {chicken, cow, pig, slime, pacman , beta_player};

                                    equip_button = equip;
                                    buy_button = buy;

                                    equiped_label = equipped;
                                }

bool game_state_shop::check_functie_unlocked(){
    if(unlocked_players.empty()){
        return false;
    }
    else {
        for(unsigned int i = 0; i <= unlocked_players.size(); i++) {
            if (all_players[player_scrolling_int] == unlocked_players[i]) {
                return true;
            }
        }
    }
    return false;
}


void game_state_shop::draw() {
    for(auto &object : objects){
        object->draw();
    }
    if(check_functie_unlocked()) {
        if(all_players[player_scrolling_int] == gameSettings.player) {
            equiped_label->draw();
        }
        else{
            equip_button->draw();
        }
    }
    else {
        buy_button->draw();

    }
    players[player_scrolling_int]->draw();
}

void game_state_shop::update() {
    for(auto &object: objects){
        object->update();
    }
    if(check_functie_unlocked()) {
        if(all_players[player_scrolling_int] == gameSettings.player) {
            equiped_label->update();
        }
        else{
            equip_button->update();
        }
    }
    else {
        buy_button->update();
    }
    sf::Event event{};
    while (window.pollEvent(event)) {}

}
