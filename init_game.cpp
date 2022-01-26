#include "init_game.hpp"

#include <fstream>

std::vector<std::string> read_values(game_settings & game){
    std::vector<std::string> list;
    //read file
    std::ifstream input("player.txt");

    if (input.is_open()) {
            while(input.is_open()){
                std::string name;
                std::string attr;
                input >> name;
                if (name == "MUNTEN") {
                    input >> attr;
                    game.coins = stoi(attr);
                } else if (name == "HIGH") {
                    input >> attr;
                    game.highscore = stoi(attr);
                } else if (name == "EQUIPPED") {
                    input >> attr;
                    game.player = attr;
                } else if (name == "PLAYER") {
                    input >> attr;
                    list.push_back(attr);
                } else if(name.empty()){
                    return list;
                }
            }
    }
    return list;
}
void save(std::vector<std::string> player_list, game_settings & game){
    std::ofstream output("player.txt");
    while(output.is_open()){
        output <<"MUNTEN " << std::to_string(game.coins) << "\n";
        output << "HIGH " << std::to_string(game.highscore)  << "\n";
        output << "EQUIPPED " << game.player  << "\n";
        for(auto player : player_list){
            output << "PLAYER " << player << "\n";
        }
        output.close();
    }
}
