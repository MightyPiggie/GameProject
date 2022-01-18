#include "sprite_factory.hpp"

std::map<std::string, std::string> sprite_factory::spritefile_read(std::ifstream & myfile) {
    while (myfile.is_open()) {
        std::string sprite_name;
        std::string file_path;
        myfile >> sprite_name;
        if (sprite_name != "") {
            myfile >> file_path;
            filenames.insert(std::pair<std::string, std::string>(sprite_name, file_path));
        } else if (sprite_name == "") {
            break;
        }
    }
    return filenames;
}

