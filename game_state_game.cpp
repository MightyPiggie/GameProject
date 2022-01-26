#include "game_state_game.hpp"

#include "simple_functions.hpp"

game_state_game::game_state_game(sf::RenderWindow & window,
                                 unsigned int width,
                                 unsigned int height,
                                 game_settings & gameSettings,
                                 state & state_t
):
                                drawable(window,{0,0},{0,0}),
                                gameSettings(gameSettings),
                                state_t(state_t),
                                width(width), 
                                height(height),
                                level1(window, gameSettings, state_t)
//                                screenshot_gamescreen{}
{
    sprite_factory sprite_reader = sprite_factory::get_instance();
    
    std::shared_ptr<window_part> left = std::make_shared<window_part>(window,vector2f_from_unsigned_ints(0,0), sprite_reader.filenames["game_bg_forrest_left"]);
    std::shared_ptr<window_part> right = std::make_shared<window_part>(window, vector2f_from_unsigned_ints(float(width)*3/4, 0),sprite_reader.filenames["game_bg_forrest_right"]);
    std::shared_ptr<window_part> game_window = std::make_shared<window_part>(window,vector2f_from_unsigned_ints(float(width)/4.f, 0), sprite_reader.filenames["background_sprite"]);
    std::shared_ptr<label> display_coins = std::make_shared<label>(window, sf::Vector2f(float(width) - 250.f, 50), std::to_string(gameSettings.coins), 25, sf::Color(163 , 235 , 177), false);
    std::shared_ptr<label> display_highscore = std::make_shared<label>(window, sf::Vector2f(float(width) - 250.f, 100), "highs: " + std::to_string(gameSettings.highscore), 25, sf::Color(163 , 235 , 177), false);
    std::shared_ptr<label> display_score = std::make_shared<label>(window, sf::Vector2f(float(width) - 250.f, 150), std::to_string(gameSettings.score), 25, sf::Color(163 , 235 , 177), false);
    std::shared_ptr<buttons> quit_gamewindow = std::make_shared<buttons>(window, 50,  vector2f_from_unsigned_ints(40,30),  [&](){window.close();},"Quit", sf::Color(163 , 235 , 177));
    std::shared_ptr<buttons> back_to_menu_gamewindow = std::make_shared<buttons>(window, 50,  vector2f_from_unsigned_ints(40, 120), [&](){state_t = MENU;},"Menu", sf::Color(163 , 235 , 177));
    drawables = {left, game_window, right, display_coins, display_score, display_highscore, quit_gamewindow, back_to_menu_gamewindow};
    labels = {display_coins , display_score};
//    screenshot_gamescreen.update(window);
    gameSettings.started = true;
}

//game_state_game::~game_state_game() {delete[] ;}

void game_state_game::draw(){
    for(auto & object : drawables){
        object->draw();
    }

    level1.draw();
}
void game_state_game::update() {
    if(gameSettings.started){
        level1.update();

        for( auto & object : drawables){
            object->update();
        }
    }
    labels[0]->update_text("Coins  " + std::to_string(gameSettings.coins));
    labels[1]->update_text("Score  " + std::to_string(gameSettings.score));

    sf::Event event{};
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if(state_t == GAME){
                //player_list[0]->move(game_drawables);
                }
            }
    }
}

/*
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
*/