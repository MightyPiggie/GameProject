#ifndef SPRITE_FACTORY_HPP
#define SPRITE_FACTORY_HPP

#include <fstream>
#include <map>
#include <string>

/// sprite_factory class
class sprite_factory{
private:
    /**
     * @brief Construct a new sprite factory object
     * 
     */
    sprite_factory();

public:
    /**
     * @brief Get the instance object
     * 
     * @return sprite_factory& 
     */
    static sprite_factory& get_instance(){
        static sprite_factory instance;
        return instance;
    }

    std::map<std::string, std::string> filenames;
};

#endif