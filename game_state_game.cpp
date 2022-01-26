#include "game_state_game.hpp"



game_state_game::game_state_game(sf::RenderWindow & window,
                                 unsigned int width,
                                 unsigned int height,
                                 std::map<std::string , std::string> & sprite_files_map,
                                 game_settings & gameSettings,
                                 state & state_t
):
                                drawable(window,{0,0},{0,0}),
                                sprite_files_map(sprite_files_map),
                                gameSettings(gameSettings),   state_t(state_t), width(width),  height(height),
                                left(window,{0,0}, sprite_files_map["game_bg_forrest_left"]),
                                right(window, {float(width)*3/4, 0},sprite_files_map["game_bg_forrest_right"]),
                                game_window(window,{float(width)/4.f, 0}, sprite_files_map["background_sprite"]),
                                player1 {window , sf::Vector2f{ 960.0, 960.0 }, sf::Vector2f{ 0.0, 0.0 }, sprite_files_map[gameSettings.player], width , height, gameSettings, state_t},
                                display_coins(window, sf::Vector2f(float(width) - 250.f, 50), "Coins "+std::to_string(gameSettings.coins), 25, sf::Color(163 , 235 , 177),gameSettings, false),
                                display_highscore(window, sf::Vector2f(float(width) - 250.f, 100), "Highs: " + std::to_string(gameSettings.highscore), 25, sf::Color(163 , 235 , 177),gameSettings, false),
                                display_score(window, sf::Vector2f(float(width) - 250.f, 150), "Score "+std::to_string(gameSettings.score), 25, sf::Color(163 , 235 , 177),gameSettings, false),
                                quit_gamewindow(window, 50,  {40,30},  [&](){window.close();},"Quit", sf::Color(163 , 235 , 177)),
                                back_to_menu_gamewindow(window, 50,  {40, 120}, [&](){state_t = MENU;},"Menu", sf::Color(163 , 235 , 177)),
                                builder1(window, sprite_files_map)
//                                screenshot_gamescreen{}
{
    drawables = {&left, &game_window, &right, &display_coins, &display_score, &display_highscore, & quit_gamewindow, &back_to_menu_gamewindow, &player1};
    updatables = {&left,&right, &game_window, &display_coins, &display_score,&display_highscore, & quit_gamewindow, &back_to_menu_gamewindow, &player1};
    game_drawables = {&player1};
//    screenshot_gamescreen.update(window);
}

//game_state_game::~game_state_game() {delete[] ;}

void game_state_game::draw(){
    drawables = {&game_window, &left,  &right, &display_coins, &display_score,&display_highscore, & quit_gamewindow, &back_to_menu_gamewindow, &player1};
    std::vector<obstacle*> undergrounds1 = builder1.return_underground_obstacles();
    drawables.insert(drawables.begin()+1, undergrounds1.begin(),  undergrounds1.begin()+undergrounds1.size());
    for( auto & object : drawables){
        object->draw();
    }
}
void game_state_game::update() {
    updatables = {&left,&right, &game_window, &display_coins, &display_score,&display_highscore, & quit_gamewindow, &back_to_menu_gamewindow, &player1};
    std::vector<obstacle*> undergrounds = builder1.return_underground_obstacles();
    updatables.insert(updatables.begin(), undergrounds.begin(), undergrounds.begin()+undergrounds.size());
    for( auto & object : updatables){
        object->update();
    }
    game_drawables = {&player1};
    game_drawables.insert(game_drawables.begin(), undergrounds.begin(), undergrounds.begin()+undergrounds.size());
    if(gameSettings.started){
        destructor();
        builder1.update();
        for( auto & object : game_drawables){
        object->lower();
        }
    }
    player1.check_dead(game_drawables);

    sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if(state_t == GAME){
                    player1.move(game_drawables);
                    }
                }
        }
}


void game_state_game::destructor(){
    for(unsigned int i =0; i < drawables.size(); i++){
        if(drawables[i]->get_position().y >= height){
            drawables.erase(drawables.begin()+i);
        }else if(drawables[i]->get_position().x >= width){
            drawables.erase(drawables.begin()+i);
        }else if(drawables[i]->get_position().x + drawables[i]->get_size().x <= 0){
            drawables.erase(drawables.erase(drawables.begin() + i));
        }
    }
}
