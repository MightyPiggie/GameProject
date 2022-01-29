#include "game_state_game.hpp"

#include <iostream>
#include "simple_functions.hpp"
#include "window_part.hpp"
#include "label_player_settings.hpp"
#include "buttons.hpp"

/// game_state_game constructor. Maakt ook direct de objecten neer voor het scherm. Dit gaat alleen om de standaard objecten.
/// Objecten van de game worden gemaakt in builder_biome.
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
{
    sprite_factory sprite_reader = sprite_factory::get_instance();

    //TODO Rectangle display voor label_player_settings werkt nog niet helemaal
    std::shared_ptr<window_part> left = std::make_shared<window_part>(window,vector2f_from_unsigned_ints(0,0), sprite_reader.filenames["game_bg_forrest_left"]);
    std::shared_ptr<window_part> right = std::make_shared<window_part>(window, vector2f_from_unsigned_ints(float(width)*3/4, 0),sprite_reader.filenames["game_bg_forrest_right"]);
    std::shared_ptr<window_part> game_window = std::make_shared<window_part>(window,vector2f_from_unsigned_ints(float(width)/4.f, 0), sprite_reader.filenames["background_sprite"]);
    //todo maak label in de update ook de achtergrond rect size aanpassen voor betere, meebewegende rectangle
    std::shared_ptr<label_player_settings_coins> display_coins = std::make_shared<label_player_settings_coins>(window, sf::Vector2f(float(width) - 250.f, 50), "coins: "+ std::to_string(gameSettings.coins), 25, sf::Color(163 , 235 , 177), gameSettings, true , sf::Color::Black);
    std::shared_ptr<label_player_settings_highscore> display_highscore = std::make_shared<label_player_settings_highscore>(window, sf::Vector2f(float(width) - 250.f, 100), "highs: " + std::to_string(gameSettings.highscore), 25, sf::Color(163 , 235 , 177), gameSettings, true , sf::Color::Black);
    std::shared_ptr<label_player_settings_score> display_score = std::make_shared<label_player_settings_score>(window, sf::Vector2f(float(width) - 250.f, 150), "score:  " + std::to_string(gameSettings.score), 25, sf::Color(163 , 235 , 177), gameSettings, true , sf::Color::Black);
    std::shared_ptr<buttons> quit_gamewindow = std::make_shared<buttons>(window, 50,  vector2f_from_unsigned_ints(40,30),  [&](){window.close();},"Quit", sf::Color(163 , 235 , 177));
    std::shared_ptr<buttons> back_to_menu_gamewindow = std::make_shared<buttons>(window, 50,  vector2f_from_unsigned_ints(40, 120), [&](){state_t = MENU;},"Menu", sf::Color(163 , 235 , 177));
    background = game_window;
    drawables = {left, right, display_coins, display_score, display_highscore, quit_gamewindow, back_to_menu_gamewindow};
}

/// tekent de objecten in game_state_game
/// Roept ook aan welke objecten daar bij horen van builder_biome
void game_state_game::draw(){
    background->draw();

    level1.draw();

    for(auto & object : drawables){
        object->draw();
    }
}

/// Update de objecten in game_state_game
/// Roept ook aan welke objecten daar bij horen van builder_biome
void game_state_game::update() {
    level1.update();

    for( auto & object : drawables){
        object->update();
    }
}
