//
// Created by Isaak van Luijk on 26/01/2022.
//

#include "label_player_settings.hpp"
#include <iostream>

label_player_settings_coins::label_player_settings_coins(sf::RenderWindow &window,
                                                         sf::Vector2f position,
                                                         std::string text_string,
                                                         int size_char,
                                                         sf::Color background_text_color,
                                                         game_settings & gameSettings,
                                                         bool rectangle_display,
                                                         sf::Color text_color
                                                         ):
                                                         label(window, position, text_string, size_char, background_text_color, rectangle_display, text_color),
                                                         gameSettings(gameSettings)
                                                         {}

void label_player_settings_coins::update() {
    if(text_string != "Coins "+ std::to_string(gameSettings.coins)){
        text_string = "Coins " + std::to_string(gameSettings.coins);
    }
}



label_player_settings_highscore::label_player_settings_highscore(sf::RenderWindow &window,
                                                         sf::Vector2f position,
                                                         std::string text_string,
                                                         int size_char,
                                                         sf::Color background_text_color,
                                                         game_settings & gameSettings,
                                                         bool rectangle_display,
                                                         sf::Color text_color
):
        label(window, position, text_string, size_char, background_text_color, rectangle_display, text_color),
        gameSettings(gameSettings)
{}

void label_player_settings_highscore::update() {
    if(text_string != "Highs "+ std::to_string(gameSettings.highscore)){
        text_string = "Highs " + std::to_string(gameSettings.highscore);
    }
}

label_player_settings_score::label_player_settings_score(sf::RenderWindow &window,
                                                                 sf::Vector2f position,
                                                                 std::string text_string,
                                                                 int size_char,
                                                                 sf::Color background_text_color,
                                                                 game_settings & gameSettings,
                                                                 bool rectangle_display,
                                                                 sf::Color text_color
):
        label(window, position, text_string, size_char, background_text_color, rectangle_display, text_color),
        gameSettings(gameSettings)
{}

void label_player_settings_score::update() {
    if(text_string != "Score "+ std::to_string(gameSettings.score)){
        text_string = "Score " + std::to_string(gameSettings.score);
    }
}