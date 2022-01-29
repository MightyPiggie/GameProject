#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "game_settings.hpp"
#include "game_states.hpp"
#include "player.hpp"
#include "line.hpp"
#include "sound_class.hpp"

/// level class
class level {
private:
    sf::RenderWindow& window;
    game_settings& game_setting;
    state& state_t;
    sound_class & the_sound_class;
    std::vector<std::shared_ptr<player>> players;
    std::vector<std::shared_ptr<line>> lines;

//    std::vector<std::shared_ptr<object>> objects;
    unsigned int ticks = 0;

    void build_line(float height = -60.0, bool force_grass_line = false);

public:
    level(sf::RenderWindow& window,
            game_settings& game_setting,
            state& state_t,
            sound_class & the_sound_class);

    void draw();
    void update();
};

#endif