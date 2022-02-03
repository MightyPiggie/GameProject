#ifndef SPRITE_FACTORY_HPP
#define SPRITE_FACTORY_HPP

#include <map>
#include <string>
#include <fstream>

// sprite_factory class
class sprite_factory{
private:
    /**
     * @brief Construct a sprite factory object
     * 
     */
    sprite_factory();

public:
    /**
     * @brief Get the instance object
     * 
     * @return sprite_factory& This returns a static spritefactory instance.
     */
    static sprite_factory& get_instance(){
        static sprite_factory instance;
        return instance;
    }

    std::map<std::string, std::string> filenames;
};

#endif
