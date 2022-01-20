#include "game_state_game.hpp"



game_state_game::game_state_game(sf::RenderWindow & window,
                                 unsigned int width,
                                 unsigned int height,
                                 std::map<std::string , std::string> & sprite_files_map,
                                 uint16_t & coins,
                                 uint16_t & score,
                                 state & state_t
):
                                drawable(window,{0,0},{0,0}),
                                sprite_files_map(sprite_files_map),
                                coins(coins), score(score),  state_t(state_t),
                                left(window,{0,0}, {float(width)/4.f, float(height)} , sf::Color(33 , 182 , 168)),
                                right(window, {float(width)*3/4, 0}, {float(width)/4.f, float(height)} , sf::Color(33 , 182 , 168)),
                                game_window(window,{float(width)/4.f, 0}, sprite_files_map["background_sprite"]),
                                player1 {window , sf::Vector2f{ 960.0, 960.0 }, sf::Vector2f{ 0.0, 0.0 }, sprite_files_map["chicken_sprite"], width , height, score},
                                test1 {window, sf::Vector2f{960.0, 0.0}, sf::Vector2f{59.0, 59.0} ,OBSTACLE, sprite_files_map["tree_sprite"]},
                                road1 {window, sf::Vector2f{float(width)/4.f, 120.0}, sf::Vector2f{59.0, 59.0} ,NON_OBSTACLE, sprite_files_map["roads_sprite"]},
                                display_coins(window, sf::Vector2f(float(width) - 175.f, 50), "Coins " + std::to_string(coins) , 25, sf::Color(163 , 235 , 177)),
                                display_score(window, sf::Vector2f(float(width) - 175.f, 150), "Score: " + std::to_string(score), 25,sf::Color(163 , 235 , 177)),
                                quit_gamewindow(window, 50,  {50,30},  [&](){window.close();},"Quit", sf::Color(163 , 235 , 177)),
                                back_to_menu_gamewindow(window, 50,  {50, 120}, [&](){state_t = MENU;},"Menu", sf::Color(163 , 235 , 177))
{
    drawables = {&left, &game_window,&road1,&right, &test1,  &display_coins, &display_score,  & quit_gamewindow, &back_to_menu_gamewindow, &player1};
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
    display_coins.update("Coins" + std::to_string(coins));
    display_score.update("Score: " + std::to_string(score));
    sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if(state_t == GAME){
                    player1.move(game_drawables);
                    }
                }
        }
}


