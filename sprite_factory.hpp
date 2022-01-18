#ifndef SPRITE_FACTORY_HPP
#define SPRITE_FACTORY_HPP

#include <iostream>
#include <fstream>
#include <map>

class sprite_factory{
protected:
    std::map<std::string, std::string> filenames = {};
public:
    std::map<std::string, std::string> spritefile_read(std::ifstream & myfile);
};

#endif