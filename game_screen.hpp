#ifndef GAME_SCREEN_HPP
#define GAME_SCREEN_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "game_states.hpp"
#include "game_settings.hpp"
#include "sound_class.hpp"


/// Game_screen class. Build om alles van te maken.
class game_screen{
private:
    unsigned int width = sf::VideoMode::getDesktopMode().width;
    unsigned int  height =  sf::VideoMode::getDesktopMode().height;
    sf::RenderWindow window{ sf::VideoMode( width,height,32), "Levensmoedige Vogel" , sf::Style::Fullscreen};
    state state_t;
    game_settings game_setting;
    std::vector<std::string> unlocked_players = {};

    /**
     * @brief The function will read the game settings.
     * 
     * @return std::vector<std::string> The returned vector are all game settings.
     */
    std::vector<std::string> init();

    sound_class the_sound_class;

    sf::Sound start_sound;
    sf::Sound window_close;

public:
    /**
     * @brief This is the main game loop. When this is called the game will start and launch.
     * 
     */
    void run();
};

#endif
