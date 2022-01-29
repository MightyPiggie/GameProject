#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "game_settings.hpp"
#include "game_states.hpp"
#include "player.hpp"
#include "builder_object.hpp"

/// builder_biome class
class builder_biome {
private:
    sf::RenderWindow& window;
    game_settings& game_setting;
    state& state_t;
    sound_class & the_sound_class_builder_biome;
    std::vector<std::shared_ptr<player>> players;
    std::vector<std::shared_ptr<builder_object>> lines;
    std::vector<std::shared_ptr<object>> objects;
    unsigned int ticks = 0;

    void build_line(float height = -60.0, bool force_grass_line = false);

public:
    builder_biome(sf::RenderWindow& window,
                  game_settings& game_setting,
                  state& state_t,
                  sound_class & the_sound_class_builder_biome);

    void draw();
    void update();
};

#endif