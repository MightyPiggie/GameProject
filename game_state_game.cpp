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
                                gameSettings(gameSettings),   state_t(state_t), width(width),  height(height)
//                                screenshot_gamescreen{}
{
    std::shared_ptr<window_part> left = std::make_shared<window_part>(window,vector2f_from_unsigned_ints(0,0), sprite_files_map["game_bg_forrest_left"]);
    std::shared_ptr<window_part> right = std::make_shared<window_part>(window, vector2f_from_unsigned_ints(float(width)*3/4, 0),sprite_files_map["game_bg_forrest_right"]);
    std::shared_ptr<window_part> game_window = std::make_shared<window_part>(window,vector2f_from_unsigned_ints(float(width)/4.f, 0), sprite_files_map["background_sprite"]);
    std::shared_ptr<player> player1 = std::make_shared<player>(window , sf::Vector2f( 960.0, 960.0 ), sf::Vector2f{ 59.0, 59.0 }, sprite_files_map[gameSettings.player], width , height, gameSettings, state_t);
    std::shared_ptr<label> display_coins = std::make_shared<label>(window, sf::Vector2f(float(width) - 250.f, 50), std::to_string(gameSettings.coins), 25, sf::Color(163 , 235 , 177), false);
    std::shared_ptr<label> display_highscore = std::make_shared<label>(window, sf::Vector2f(float(width) - 250.f, 100), "highs: " + std::to_string(gameSettings.highscore), 25, sf::Color(163 , 235 , 177), false);
    std::shared_ptr<label> display_score = std::make_shared<label>(window, sf::Vector2f(float(width) - 250.f, 150), std::to_string(gameSettings.score), 25, sf::Color(163 , 235 , 177), false);
    std::shared_ptr<buttons> quit_gamewindow = std::make_shared<buttons>(window, 50,  vector2f_from_unsigned_ints(40,30),  [&](){window.close();},"Quit", sf::Color(163 , 235 , 177));
    std::shared_ptr<buttons> back_to_menu_gamewindow = std::make_shared<buttons>(window, 50,  vector2f_from_unsigned_ints(40, 120), [&](){state_t = MENU;},"Menu", sf::Color(163 , 235 , 177));
    std::shared_ptr<builder> builder1 = std::make_shared<builder>(window, sprite_files_map);
    drawables = {left, game_window, right, display_coins, display_score, display_highscore, quit_gamewindow, back_to_menu_gamewindow, player1};
    game_drawables = {};
    labels = {display_coins , display_score};
    player_list = {player1};
    builder_list = {builder1};
//    screenshot_gamescreen.update(window);
}

//game_state_game::~game_state_game() {delete[] ;}

void game_state_game::draw(){
    std::vector<std::shared_ptr<obstacle>> undergrounds = std::make_shared<builder_list> builder_list[0]->return_underground_obstacles();
    drawables.insert(drawables.begin()+1, undergrounds.begin(),  undergrounds.begin()+undergrounds.size());
    for( auto & object : drawables){
        object->draw();
    }
}
void game_state_game::update() {
    std::vector<std::shared_ptr<obstacle>> undergrounds = builder_list[0]->return_underground_obstacles();
    drawables.insert(drawables.begin(), undergrounds.begin(), undergrounds.begin()+undergrounds.size());
    for( auto & object : drawables){
        object->update();
    }
    game_drawables.insert(game_drawables.begin(), undergrounds.begin(), undergrounds.begin()+undergrounds.size());
    if(gameSettings.started){
        destructor();
        builder_list[0]->update();
        for( auto & object : game_drawables){
        object->lower();
        }
    }
    labels[0]->update_text("Coins  " + std::to_string(gameSettings.coins));
    labels[1]->update_text("Score  " + std::to_string(gameSettings.score));
    player_list[0]->check_dead(game_drawables);

    sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if(state_t == GAME){
                    player_list[0]->move(game_drawables);
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
