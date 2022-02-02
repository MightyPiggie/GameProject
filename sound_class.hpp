#ifndef SOUND_CLASS_HPP
#define SOUND_CLASS_HPP

#include <SFML/Audio.hpp>
#include <map>


class sound_class{
private:
std::map<std::string, sf::SoundBuffer> sounds;
public:
    /**
     * @brief Set the sound buffer object
     * 
     * @param name_sound 
     * @param filename 
     */
    void set_sound_buffer(const std::string & name_sound, const std::string & filename);

    /**
     * @brief Get the sound buffer object
     * 
     * @param name_sound 
     * @return sf::SoundBuffer& 
     */
    sf::SoundBuffer &get_sound_buffer(const std::string & name_sound);
};

#endif
