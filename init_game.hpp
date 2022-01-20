#ifndef INIT_GAME_HPP
#define INIT_GAME_HPP

#include <vector>
#include <string>

std::vector<std::string> read_values(uint16_t & munten, uint16_t & highscore);
void save(std::vector<std::string> player_list, uint16_t & coins, uint16_t & highscore);
#endif