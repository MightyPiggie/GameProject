#ifndef GAME_SCREEN_HPP
#define GAME_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "game_states.hpp"

class game_screen{
private:
    unsigned int width = sf::VideoMode::getDesktopMode().width;
    unsigned int  height =  sf::VideoMode::getDesktopMode().height;
    unsigned int ticks = 0;
    sf::RenderWindow window{ sf::VideoMode( width,height,32), "SFML window" , sf::Style::Fullscreen};
    state state_t;
    //uint16_t score = 0;
    uint16_t highscore;
    uint16_t coins;
    std::vector<std::string> unlocked_players = {};

    std::vector<std::string> init();
    
public:
    void run();
};

#endif