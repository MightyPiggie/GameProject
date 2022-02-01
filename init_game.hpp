#ifndef INIT_GAME_HPP
#define INIT_GAME_HPP

#include <vector>
#include <string>
#include "game_settings.hpp"

/**
 * @brief The read_values will read all the game settings from the player.txt.
 * 
 * @param game A reference to all game settings of the game.
 * @return std::vector<std::string> The vector will contain a list of all unlocked characters.
 */
std::vector<std::string> read_values(game_settings & game);

/**
 * @brief The save function will write the current game settings and unlocked characters to the players.txt
 * 
 * @param player_list The currently unlocked characters.
 * @param game A reference to all game settings of the game.
 */
void save(std::vector<std::string> player_list,
          game_settings & game);

#endif
