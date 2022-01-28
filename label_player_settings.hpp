//
// Created by Isaak van Luijk on 26/01/2022.
//

#ifndef LABEL_PLAYER_SETTINGS_HPP
#define LABEL_PLAYER_SETTINGS_HPP

#include "label.hpp"
#include "game_settings.hpp"

/// label_player_settings_coins class, heritage van label
class label_player_settings_coins : public label{
protected:
    game_settings & gameSettings;
public:
    label_player_settings_coins(sf::RenderWindow &window,
                                sf::Vector2f position,
                                std::string text_string,
                                int size_char,
                                sf::Color background_text_color,
                                game_settings & gameSettings,
                                bool rectangle_display = true,
                                sf::Color text_color = sf::Color::Black);
    void update() override;
};

/// label_player_settings_highscore class, heritage van label
class label_player_settings_highscore : public label{
protected:
    game_settings & gameSettings;
public:
    label_player_settings_highscore(sf::RenderWindow &window,
                                sf::Vector2f position,
                                std::string text_string,
                                int size_char,
                                sf::Color background_text_color,
                                game_settings & gameSettings,
                                bool rectangle_display = true,
                                sf::Color text_color = sf::Color::Black);
    void update() override;
};

/// label_player_settings_score class, heritage van label
class label_player_settings_score : public label{
protected:
    game_settings & gameSettings;
public:
    label_player_settings_score(sf::RenderWindow &window,
                                    sf::Vector2f position,
                                    std::string text_string,
                                    int size_char,
                                    sf::Color background_text_color,
                                    game_settings & gameSettings,
                                    bool rectangle_display = true,
                                    sf::Color text_color = sf::Color::Black);
    void update() override;
};


#endif //LABEL_PLAYER_SETTINGS_HPP
