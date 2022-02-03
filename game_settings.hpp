#ifndef GAME_SETTINGS_HPP
#define GAME_SETTINGS_HPP

#include <string>

// Gamesettings basis. Wordt aangepast door init om de laatste gegevens in te laden.

/**
 * @brief The game_settings struct contains all the game settings.
 * 
 */
struct game_settings{
    uint16_t score = 0;
    uint16_t highscore = 0;
    uint16_t coins = 0;
    bool started = false;
    bool sound = true;
    std::string player = "chicken_player";
};

#endif