#ifndef INIT_GAME_HPP
#define INIT_GAME_HPP
std::vector<std::string> read(){
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
                    list.insert(list.begin(), attr);
                } else if (name == "HIGH") {
                    input >> attr;
                    list.insert(list.begin() + 1, attr);
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