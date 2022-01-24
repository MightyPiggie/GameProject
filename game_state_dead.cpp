#include "game_state_dead.hpp"


game_state_dead::game_state_dead(sf::RenderWindow & window,
                                 unsigned int width,
                                 unsigned int height,
                                 std::map<std::string , std::string> & sprite_files_map,
                                 state & state_t
):
        drawable(window,{0,0},{0,0}),
        sprite_files_map(sprite_files_map),
        state_t(state_t),
        dead_window(window,{0,0}, {float(width), float(height)} , sf::Color(98 , 0 , 0)),
//        screenshot_gamescreen(screenshot_gamescreen),
        quit_game_button(window, 50,  {40,30},  [&](){window.close();},"Quit", sf::Color(81, 81 ,81)),
        back_to_menu_button(window, 50,  {40, 120}, [&](){state_t = MENU;},"Menu", sf::Color(81, 81 ,81)),
        restart_button(window, 30,  {vector2f_from_unsigned_ints(width/2 - 100, height*2.5/4 )}, [&](){state_t = GAME;},"Restart", sf::Color(81, 81 ,81)),
        dead_message(window,vector2f_from_unsigned_ints(width/2 - 250, height/2 ),"GAME OVER",60,sf::Color(81, 81 ,81))
{
    objects = {&dead_window , &quit_game_button , &back_to_menu_button ,&restart_button, &dead_message};
}

void game_state_dead::draw(){
    objects = {&dead_window , &quit_game_button , &back_to_menu_button , &restart_button, &dead_message};
    for( auto & object : objects){
        object->draw();
    }
}

void game_state_dead::update() {
    for(auto &object : objects){
        object->update();
    }
    sf::Event event{};
    while (window.pollEvent(event)) {}
}



