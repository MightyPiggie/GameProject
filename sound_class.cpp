//
// Created by Isaak van Luijk on 28/01/2022.
//

#include "sound_class.hpp"
#include <iostream>

void sound_class::set_sound_buffer(const std::string &name, const std::string &Filename){
    if(sounds.count(name)==0) {
        sf::SoundBuffer temp;
        if (temp.loadFromFile(Filename)) {
            sounds[name] = temp;
        }
//        else {
//            throw load_exception("Sounds", name, Filename);
//        }
    }
}
sf::SoundBuffer &sound_class::get_sound_buffer(const std::string &name) {
    if (sounds.count(name)==1){
        return sounds.at(name);
    }
    return sounds.at(name);
//    throw return_exception("Sounds", name);
}




sf::SoundBuffer sound_choice(const std::string &filename);

void loadSoundBufferFromFile(const std::string &name, const std::string &Filename);
//sf::SoundBuffer GetSoundBuffer(const std::string &name);