#include "game_state_shop.hpp"
#include <iostream>

game_state_shop::game_state_shop(sf::RenderWindow& window,
                                 state & state_t,
                                 unsigned int width,
                                 unsigned int height,
                                 std::vector<std::string> & unlocked_players,
                                 std::map<std::string,
                                 std::string> & sprite_files_map
                                 ):
                                 drawable(window,{0,0}, {0,0}),
                                 state_t(state_t),
                                 unlocked_players(unlocked_players),
                                 sprite_files_map(sprite_files_map),
                                 shop_window(window, {0,0}, {float(width), float(height)}, sf::Color(33,182,168)),
                                 quit_gamewindow(window, 50,  {40,30},  [&](){window.close();},"Quit", sf::Color(163 , 235 , 177)),
                                 back_to_menu_from_gamewindow(window, 50,  {40, 120}, [&](){state_t = MENU;},"Menu", sf::Color(163 , 235 , 177)),

                                 /// Shop buttons
                                 //Todo: Moet nog netjes neergezet worden.
                                 previeus_player_button(window, 50,{float(width)/2-500.f, float(height) - 200.f},[&](){if(player_scrolling_int <= 0){player_scrolling_int = 0;}else{player_scrolling_int--;} sf::sleep(sf::milliseconds(100));},"prev",sf::Color(163 , 235 , 177)),
                                 buy_button(window, 50, {float(width)/2-200.f, float(height) - 200.f}, [&](){std::cout << "Unlock player :)";}, "Buy", sf::Color(163 , 235 , 177)),
                                 equipe_button(window, 50,{float(width)/2+200.f, float(height) - 200.f},[](){std::cout << "Zet als player neer";},"Equip",sf::Color(163 , 235 , 177)),
                                 next_player_button(window, 50,{float(width)/2+500.f, float(height) - 200.f},[&](){if(player_scrolling_int > players.size()){player_scrolling_int = players.size();}else{player_scrolling_int++;} sf::sleep(sf::milliseconds(100));},"next",sf::Color(163 , 235 , 177)),

                                 ///Steeds players toevoegen aan deze lijst. Deze komen in een vector. Door deze loop je steeds
                                 chicken(window, {float(width/2 - 360),  400.f}, sprite_files_map[all_players[0]]),
                                 slime(window, {float(width/2 - 360),  400.f}, sprite_files_map[all_players[1]]),
                                 pacman(window, {float(width/2 - 360),  400.f}, sprite_files_map[all_players[2]])
{
    objects = {&shop_window,&quit_gamewindow,&back_to_menu_from_gamewindow};
    /// Lijst van players die er zijn? Kan misschien anders
    players = {&chicken, &slime, &pacman};

    /// Wou het wat aanpassen dat de buy button vervangen wordt door de equip button indien die gekocht is.
    scrol_objects = {&previeus_player_button, &buy_button, &equipe_button, &next_player_button};

}

void game_state_shop::draw() {
    for(auto &object : objects){
        object->draw();
    }
    for(auto &object : scrol_objects){
        object->draw();
    }
}

void game_state_shop::update() {
    for(auto &object: objects){
        object->update();
    }
    for(auto &object : scrol_objects){
        object->update();
    }
    if(player_scrolling_int > players.size()){
        player_scrolling_int = players.size();
    }
    players[player_scrolling_int]->draw();

    sf::Event event{};
    while (window.pollEvent(event)) {}

}