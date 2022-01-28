#include "sprite_factory.hpp"

sprite_factory::sprite_factory() {
    std::ifstream myfile("sprite_file.txt");
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
}
