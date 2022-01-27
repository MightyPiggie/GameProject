#ifndef GAME_SCREEN_HPP
#define GAME_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <map>

#include "game_states.hpp"
#include "label.hpp"
#include "game_settings.hpp"


/// Game_screen class. Build om alles van te maken.
class game_screen{
private:
    unsigned int width = sf::VideoMode::getDesktopMode().width;
    unsigned int  height =  sf::VideoMode::getDesktopMode().height;
    //unsigned int ticks = 0;
    sf::RenderWindow window{ sf::VideoMode( width,height,32), "Levensmoedige Vogel" , sf::Style::Fullscreen};
    state state_t;
    game_settings game_setting;
    std::vector<std::string> unlocked_players = {};
    std::vector<std::string> init();
    
public:
    void run();
};

#endif