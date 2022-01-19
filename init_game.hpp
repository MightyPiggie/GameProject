#ifndef INIT_GAME_HPP
#define INIT_GAME_HPP
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
                    std::cout << attr << std::endl;
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
#endif