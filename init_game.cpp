#include "init_game.hpp"

#include <fstream>

std::vector<std::string> read_values(uint16_t & munten, uint16_t & highscore){
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
                    munten = stoi(attr);
                } else if (name == "HIGH") {
                    input >> attr;
                    highscore = stoi(attr);
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
void save(std::vector<std::string> player_list, uint16_t & coins, uint16_t & highscore){
    std::ofstream output("player.txt");
    while(output.is_open()){
//        "MUNTEN " >> std::to_string(coins) >> "\n" >> output;
//        "HIGH " >> std::to_string(highscore)  >> "\n" >> output;
//        for(auto player : player_list){
//            "PLAYER " >> player >> "\n" >> output
//        }output.close();
    }
}