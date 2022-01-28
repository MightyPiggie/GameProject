//
// Created by Isaak van Luijk on 28/01/2022.
//

#ifndef SOUND_CLASS_HPP
#define SOUND_CLASS_HPP

#include <SFML/Audio.hpp>
#include <map>


class sound_class{
private:
std::map<std::string, sf::SoundBuffer> sounds;
public:
    void set_sound_buffer(const std::string & name_sound, const std::string & filename);
    sf::SoundBuffer &get_sound_buffer(const std::string & name_sound);
};

#endif
