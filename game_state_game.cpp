#include "game_state_game.hpp"



game_state_game::game_state_game(sf::RenderWindow & window,
                                 unsigned int width,
                                 unsigned int height,
                                 std::map<std::string , std::string> & sprite_files_map,
                                 uint16_t & coins,
                                 state & state_t
):
                                drawable(window,{0,0},{0,0}),
                                sprite_files_map(sprite_files_map),
                                coins(coins), state_t(state_t),
                                left(window,{0,0}, {float(width)/4.f, float(height)} , sf::Color(33 , 182 , 168)),
                                right(window, {float(width)*3/4, 0}, {float(width)/4.f, float(height)} , sf::Color(33 , 182 , 168)),
                                game_window(window,{float(width)/4.f, 0}, sprite_files_map["background_sprite"]),
                                player1 {window , sf::Vector2f{ 960.0, 960.0 }, sf::Vector2f{ 0.0, 0.0 }, sprite_files_map["chicken_sprite"], width , height},
                                test1 {window, sf::Vector2f{960.0, 0.0}, sf::Vector2f{59.0, 59.0} ,OBSTACLE, sprite_files_map["tree_sprite"]},
                                road1 {window, sf::Vector2f{float(width)/4.f, 120.0}, sf::Vector2f{59.0, 59.0} ,NON_OBSTACLE, sprite_files_map["roads_sprite"]},
                                display_coins(window, sf::Vector2f(float(width) - 200.f, 200), std::to_string(coins), 25, sf::Color::Green),
                                quit_gamewindow(window, 50,  {40,30},  [&](){window.close();},"Quit", sf::Color(163 , 235 , 177)),
                                back_to_menu_gamewindow(window, 50,  {40, 120}, [&](){state_t = MENU;},"Menu", sf::Color(163 , 235 , 177))
{
    drawables = {&left,&right, &game_window, &test1, &road1, &display_coins, & quit_gamewindow, &back_to_menu_gamewindow, &player1};
    game_drawables = {&player1, &test1, &road1};
}
void game_state_game::draw(){
    for( auto & object : drawables){
        object->draw();
    }
}
void game_state_game::update() {
    for( auto & object : drawables){
        object->update();
    }
    for( auto & object : game_drawables){
        object->lower();
    }
    sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if(state_t == GAME){
                    player1.move(game_drawables);
                    }
                }
        }
}


