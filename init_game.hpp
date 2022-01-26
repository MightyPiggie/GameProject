#ifndef INIT_GAME_HPP
#define INIT_GAME_HPP

#include <vector>
#include <string>
#include "game_settings.hpp"

std::vector<std::string> read_values(game_settings & game);

void save(std::vector<std::string> player_list,
          game_settings & game);

#endif