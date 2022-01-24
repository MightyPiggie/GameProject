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
                                gameSettings(gameSettings),   state_t(state_t),
                                left(window,{0,0}, sprite_files_map["game_bg_forrest_left"]),
                                right(window, {float(width)*3/4, 0},sprite_files_map["game_bg_forrest_right"]),
                                game_window(window,{float(width)/4.f, 0}, sprite_files_map["background_sprite"]),
                                player1 {window , sf::Vector2f{ 960.0, 960.0 }, sf::Vector2f{ 0.0, 0.0 }, sprite_files_map["chicken_sprite"], width , height, gameSettings},
                                display_coins(window, sf::Vector2f(float(width) - 250.f, 50), std::to_string(gameSettings.coins), 25, sf::Color(163 , 235 , 177), false),
                                display_highscore(window, sf::Vector2f(float(width) - 250.f, 100), "highs: " + std::to_string(gameSettings.highscore), 25, sf::Color(163 , 235 , 177), false),
                                display_score(window, sf::Vector2f(float(width) - 250.f, 150), std::to_string(gameSettings.score), 25, sf::Color(163 , 235 , 177), false),
                                quit_gamewindow(window, 50,  {40,30},  [&](){window.close();},"Quit", sf::Color(163 , 235 , 177)),
                                back_to_menu_gamewindow(window, 50,  {40, 120}, [&](){state_t = MENU;},"Menu", sf::Color(163 , 235 , 177)),
                                builder1(window, sprite_files_map),
                                tree {window, sf::Vector2f{960.0, 0.0}, sf::Vector2f{59.0, 59.0} ,OBSTACLE, sprite_files_map["tree_sprite"]}
{
    drawables = {&left, &game_window, &tree, &right, &display_coins, &display_score, &display_highscore ,& quit_gamewindow, &back_to_menu_gamewindow, &player1};
    updatables = {&left,&right, &game_window, &display_coins, &display_score, &display_highscore, & quit_gamewindow, &back_to_menu_gamewindow, &player1, &builder1, &tree};
    game_drawables = {&player1, &tree};
}
void game_state_game::draw(){
    drawables = {&left, &game_window, &tree,  &right, &display_coins, &display_score, &display_highscore, & quit_gamewindow, &back_to_menu_gamewindow, &player1};
    std::vector<obstacle*> undergrounds1 = builder1.return_underground();
    drawables.insert(drawables.begin()+2, undergrounds1.begin(),  undergrounds1.begin()+undergrounds1.size());
    for( auto & object : drawables){
        object->draw();
    }
}
void game_state_game::update() {
    for( auto & object : updatables){
        object->update();
    }
    game_drawables = {&player1, &tree};
    std::vector<obstacle*> undergrounds = builder1.return_underground();
    game_drawables.insert(game_drawables.begin(), undergrounds.begin(), undergrounds.begin()+undergrounds.size());
    if(gameSettings.started){
        for( auto & object : game_drawables){
        object->lower();
        }
    }
    display_coins.update_text("Coins  " + std::to_string(gameSettings.coins));
    display_score.update_text("Score  " + std::to_string(gameSettings.score));

    sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if(state_t == GAME){
                    player1.move(game_drawables);
                    }
                }
        }
}


