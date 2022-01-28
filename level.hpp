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
     * @brief The build_line function builds a line when its called. The created line is placed into the lines vector as a shared pointer.
     * 
     * @param height The default value is -60, if it is specified is is the height on the screen where the line is placed.
     * @param force_grass_line The default value is false, if it is specified it will force a grass line.
     */
    void build_line(float height = -60.0, bool force_grass_line = false);

public:
    /**
     * @brief Construct a new level object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param game_setting A reference to all game settings of the game.
     * @param state_t a refence to the state of which the game is in. 
     */
    level(sf::RenderWindow& window,
            game_settings& game_setting,
            state& state_t);

    /**
     * @brief The draw function calls the draw function of all players and all lines.
     *
     */
    void draw();

    /**
     * @brief The update function calls the update, lower and build_line for every player and line.
     * 
     */
    void update();
};

#endif