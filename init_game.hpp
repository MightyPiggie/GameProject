#ifndef INIT_GAME_HPP
#define INIT_GAME_HPP

#include <vector>
#include <string>
#include "game_settings.hpp"

/**
 * @brief 
 * 
 * @param game 
 * @return std::vector<std::string> 
 */
std::vector<std::string> read_values(game_settings & game);

/**
 * @brief 
 * 
 * @param player_list 
 * @param game 
 */
void save(std::vector<std::string> player_list,
          game_settings & game);

#endif
