#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "game_settings.hpp"
#include "game_states.hpp"
#include "player.hpp"
#include "line.hpp"

/// level class
class level {
private:
    sf::RenderWindow& window;
    game_settings& game_setting;
    state& state_t;
    std::vector<std::shared_ptr<player>> players;
    std::vector<std::shared_ptr<line>> lines;
    std::vector<std::shared_ptr<object>> objects;
    unsigned int ticks = 0;

    /**
     * @brief 
     * 
     * @param height 
     * @param force_grass_line 
     */
    void build_line(float height = -60.0, bool force_grass_line = false);

public:
    /**
     * @brief Construct a new level object
     * 
     * @param window 
     * @param game_setting 
     * @param state_t 
     */
    level(sf::RenderWindow& window,
            game_settings& game_setting,
            state& state_t);

    /**
     * @brief 
     *
     */
    void draw();

    /**
     * @brief 
     * 
     */
    void update();
};

#endif