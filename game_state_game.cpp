#include "game_state_game.hpp"

#include <iostream>
#include "simple_functions.hpp"
#include "window_part.hpp"
#include "label_player_settings.hpp"
#include "buttons.hpp"

// game_state_game constructor. Maakt ook direct de objecten neer voor het scherm. Dit gaat alleen om de standaard objecten.
// Objecten van de game worden gemaakt in builder_biome.
game_state_game::game_state_game(sf::RenderWindow & window,
                                 unsigned int width,
                                 unsigned int height,
                                 game_settings & gameSettings,
                                 state & state_t,
                                 sound_class & the_sound_class_ingame
):
                                drawable(window,{0,0},{0,0}),
                                gameSettings(gameSettings),
                                state_t(state_t),
                                width(width),
                                height(height),
                                level1(window, gameSettings, state_t, the_sound_class_ingame),
                                the_sound_class_ingame(the_sound_class_ingame)
{
    sprite_factory sprite_reader = sprite_factory::get_instance();

    click_sound.setBuffer(the_sound_class_ingame.get_sound_buffer("click_sound"));
    background_music_game.setBuffer(the_sound_class_ingame.get_sound_buffer("menu_background"));
    background_music_game.setVolume(10.f);

    std::shared_ptr<window_part> left = std::make_shared<window_part>(window,vector2f_from_unsigned_ints(0,0), sprite_reader.filenames["game_bg_forrest_left"]);
    std::shared_ptr<window_part> right = std::make_shared<window_part>(window, vector2f_from_unsigned_ints(float(width)*3/4, 0),sprite_reader.filenames["game_bg_forrest_right"]);
    std::shared_ptr<window_part> game_window = std::make_shared<window_part>(window,vector2f_from_unsigned_ints(float(width)/4.f, 0), sprite_reader.filenames["background_sprite"]);
    std::shared_ptr<label_player_settings_coins> display_coins = std::make_shared<label_player_settings_coins>(window, sf::Vector2f(float(width) - 250.f, 50), std::to_string(gameSettings.coins), 25, sf::Color(163 , 235 , 177), gameSettings, false);
    std::shared_ptr<label_player_settings_highscore> display_highscore = std::make_shared<label_player_settings_highscore>(window, sf::Vector2f(float(width) - 250.f, 100), "highs: " + std::to_string(gameSettings.highscore), 25, sf::Color(163 , 235 , 177), gameSettings, false);
    std::shared_ptr<label_player_settings_score> display_score = std::make_shared<label_player_settings_score>(window, sf::Vector2f(float(width) - 250.f, 150), std::to_string(gameSettings.score), 25, sf::Color(163 , 235 , 177), gameSettings, false);
    std::shared_ptr<buttons> quit_gamewindow = std::make_shared<buttons>(window, 50,  vector2f_from_unsigned_ints(40,30),  [&](){if(gameSettings.sound){click_sound.play();}background_music_game.stop(); window.close();},"Quit", sf::Color(163 , 235 , 177));
    std::shared_ptr<buttons> back_to_menu_gamewindow = std::make_shared<buttons>(window, 50,  vector2f_from_unsigned_ints(40, 120), [&](){if(gameSettings.sound){click_sound.play();} background_music_game.stop(); state_t = MENU;},"Menu", sf::Color(163 , 235 , 177));
    std::shared_ptr<buttons> pauze_button = std::make_shared<buttons>(window, 40,  vector2f_from_unsigned_ints(float(width) - 300.f,float(height)-200.f),  [&](){if(gameSettings.sound){click_sound.play();} gameSettings.started = !gameSettings.started; sf::sleep(sf::milliseconds(200));},"Pauze", sf::Color(163 , 235 , 177));
    std::shared_ptr<buttons> sound_button_in_game_window = std::make_shared<buttons>(window,50,vector2f_from_unsigned_ints(40, float(height)-200.f),[&](){click_sound.play(); gameSettings.sound = !gameSettings.sound;  sf::sleep(sf::milliseconds(200));},"Sound",sf::Color(163 , 235 , 177));
    background = game_window;
    drawables = {left, right, display_coins, display_score, display_highscore, quit_gamewindow, back_to_menu_gamewindow, pauze_button , sound_button_in_game_window};
}

// tekent de objecten in game_state_game
// Roept ook aan welke objecten daar bij horen van level
void game_state_game::draw(){
    background->draw();

    level1.draw();

    for(auto & object : drawables){
        object->draw();
    }
}

// Update de objecten in game_state_game
// Roept ook aan welke objecten daar bij horen van builder_biome
void game_state_game::update() {
    if(state_t == GAME){
        if(gameSettings.sound){
            if (background_music_game.getStatus() != sf::SoundSource::Playing) {
                background_music_game.play();
            }
        }
        if(!gameSettings.sound){
            background_music_game.stop();
        }
    }

    level1.update();

    for( auto & object : drawables){
        object->update();
    }
}
