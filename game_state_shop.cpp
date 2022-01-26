#include "game_state_shop.hpp"

#include "sprite_factory.hpp"

game_state_shop::game_state_shop(sf::RenderWindow& window,
                                 state & state_t,
                                 unsigned int width,
                                 unsigned int height,
                                 std::vector<std::string> & unlocked_players,
                                 game_settings & gameSettings
                                 ):
                                 drawable(window,{0,0}, {0,0}),
                                 state_t(state_t),
                                 unlocked_players(unlocked_players),
                                 gameSettings(gameSettings)
                                {
                                    sprite_factory sprite_reader = sprite_factory::get_instance(); 
                                    std::shared_ptr<window_part> shop_window = std::make_shared<window_part>(window, vector2f_from_unsigned_ints(0,0),vector2f_from_unsigned_ints(width,height), sf::Color(33,182,168));
                                    std::shared_ptr<buttons> quit_gamewindow = std::make_shared<buttons>(window, 50,  vector2f_from_unsigned_ints(40,30),  [&](){ save(unlocked_players, gameSettings) ;window.close();},"Quit", sf::Color(163 , 235 , 177));
                                    std::shared_ptr<buttons> back_to_menu_from_gamewindow = std::make_shared<buttons>(window, 50,  vector2f_from_unsigned_ints(40, 120), [&](){save(unlocked_players, gameSettings); state_t = MENU;},"Menu", sf::Color(163 , 235 , 177));

                                            /// Shop buttons
                                            //Todo: Moet nog netjes neergezet worden.
                                    std::shared_ptr<buttons> previeus_player_button = std::make_shared<buttons>(window,
                                                                                                                50,
                                                                                                                vector2f_from_unsigned_ints(width/2-500.f, height - 200.f),
                                                                                                                [&](){if(player_scrolling_int <= 0){
                                                                                                                    player_scrolling_int = players.size()-1;
                                                                                                                }
                                                                                                                else{player_scrolling_int--;
                                                                                                                }
                                                                                                                sf::sleep(sf::milliseconds(100));
                                                                                                                },
                                                                                                                "prev",
                                                                                                                sf::Color(163 , 235 , 177));
                                    std::shared_ptr<buttons> buy_button = std::make_shared<buttons>(window,
                                                                                                    50,
                                                                                                    vector2f_from_unsigned_ints(width/2-100, height - 200),
                                                                                                    [&](){unlocked_players.push_back(all_players[player_scrolling_int]);
                                                                                                        sf::sleep(sf::milliseconds(100));
                                                                                                        },
                                                                                                        "Buy",
                                                                                                        sf::Color(163 , 235 , 177));
                                    std::shared_ptr<buttons> equip_button = std::make_shared<buttons>(window,
                                                                                                      50,
                                                                                                      vector2f_from_unsigned_ints(width/2-100, height - 200),
                                                                                                      [&](){gameSettings.player = all_players[player_scrolling_int]; std::cout << gameSettings.player << std::endl;
                                                                                                        sf::sleep(sf::milliseconds(100));
                                                                                                        },
                                                                                                        "Equip",
                                                                                                        sf::Color(163 , 235 , 177));
                                    std::shared_ptr<label> equipped_label = std::make_shared<label>(window,vector2f_from_unsigned_ints(width/2-100, height - 200), "Equipped",50,sf::Color(163 , 235 , 177));
                                    std::shared_ptr<buttons> next_player_button = std::make_shared<buttons>(window,
                                                                                                            50,
                                                                                                            vector2f_from_unsigned_ints(width/2+500,height - 200),
                                                                                                            [&](){if(player_scrolling_int >= players.size()-1){
                                                                                                                player_scrolling_int = 0;
                                                                                                            }
                                                                                                            else{player_scrolling_int++;
                                                                                                            }
                                                                                                            sf::sleep(sf::milliseconds(100));
                                                                                                            },
                                                                                                            "next",
                                                                                                            sf::Color(163 , 235 , 177));

                                            ///Steeds players toevoegen aan deze lijst. Deze komen in een vector. Door deze loop je steeds
                                    sf::Vector2f player_layout_position = vector2f_from_unsigned_ints(width/2 - 180,  400);
                                    std::shared_ptr<window_part> chicken = std::make_shared<window_part>(window, player_layout_position, sprite_reader.filenames[all_players[0]+"_shop"]);
                                    std::shared_ptr<window_part> slime = std::make_shared<window_part>(window, player_layout_position, sprite_reader.filenames[all_players[1]+"_shop"]);
                                    std::shared_ptr<window_part> pacman = std::make_shared<window_part>(window, player_layout_position, sprite_reader.filenames[all_players[2]+"_shop"]);

                                    objects = {shop_window,quit_gamewindow,back_to_menu_from_gamewindow, previeus_player_button, next_player_button};
                                    /// Lijst van players die er zijn? Kan misschien anders
                                    players = {chicken, slime, pacman};

                                    /// Wou het wat aanpassen dat de buy button vervangen wordt door de equip button indien die gekocht is.
                                    scrol_objects_purchased = {equip_button};
                                    scrol_objects_not_purchased = {buy_button};

                                    /// Deze wordt niet gebruikt
                                    //unlocked_players = {chicken};
                                    player_equipped_test = {equipped_label};
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
            for (auto &object: player_equipped_test) {
                object->draw();
            }
        }
        else{
            for (auto &object: scrol_objects_purchased) {
                object->draw();
            }
        }
    }
    else {
        for (auto &object2: scrol_objects_not_purchased) {
            object2->draw();
        }
    }
    players[player_scrolling_int]->draw();
}

void game_state_shop::update() {
    for(auto &object: objects){
        object->update();
    }
    if(check_functie_unlocked()) {
        if(all_players[player_scrolling_int] == gameSettings.player) {
            for (auto &object: player_equipped_test) {
                object->update();
            }
        }
        else{
            for (auto &object: scrol_objects_purchased) {
                object->update();
            }
        }
    }
    else {
        for (auto &object2: scrol_objects_not_purchased) {
            object2->update();
        }
    }
    sf::Event event{};
    while (window.pollEvent(event)) {}

}