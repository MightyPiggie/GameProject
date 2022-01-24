#include "game_state_shop.hpp"

game_state_shop::game_state_shop(sf::RenderWindow& window,state & state_t, unsigned int width,unsigned int height, std::vector<std::string> & unlocked_players, std::map<std::string, std::string> & sprite_files_map): drawable(window,
                                                                                                                             {0,0}, {0,0}),
                                                                                                                             state_t(state_t), unlocked_players(unlocked_players), sprite_files_map(sprite_files_map),
                                                                                                                             shop_window(window, {0,0}, {float(width), float(height)}, sf::Color(33,182,168)),
                                                                                                                    quit_gamewindow(window, 50,  {40,30},  [&](){window.close();},"Quit", sf::Color(163 , 235 , 177)),
                                                                                                                    back_to_menu_from_gamewindow(window, 50,  {40, 120}, [&](){state_t = MENU;},"Menu", sf::Color(163 , 235 , 177)),
                                                                                                                    first_buy_button(window, 50, {float(width)/2-120.f/2, float(height) - 200.f}, [&](){chosen_player = all_players[1];}, "Buy", sf::Color(163 , 235 , 177)),
                                                                                                                    first(window, {float(width/4 - 60 * 3),  400.f}, sprite_files_map[all_players[0]]),
                                                                                                                    second(window, {float(width/2 - 60 * 2.5), 400.f}, sprite_files_map[all_players[1]]),
                                                                                                                    third(window, {float(width/2*1.5 - 60 * 2.5), 400.f}, sprite_files_map[all_players[2]])
{
    first.rescale({5,5});
    second.rescale({5,5});
    third.rescale({5,5});
    objects = {&shop_window,&quit_gamewindow,&back_to_menu_from_gamewindow, &first_buy_button,   &first, &second, &third};
}

void game_state_shop::draw() {
    for(auto &object : objects){
        object->draw();
    }
}

void game_state_shop::update() {
    for(auto &object: objects){
        object->update();
    }

    sf::Event event{};
    while (window.pollEvent(event)) {}

}