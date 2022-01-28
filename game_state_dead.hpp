#ifndef GAME_STATE_DEAD_HPP
#define GAME_STATE_DEAD_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "simple_functions.hpp"
#include "game_state_game.hpp"
#include "drawable.hpp"
#include "window_part.hpp"
#include "label.hpp"
#include "sprite_factory.hpp"
#include "buttons.hpp"


/// game_state_dead class, heritage van drawable
class game_state_dead : public drawable{
private:
    state & state_t;
    std::vector<std::shared_ptr<drawable>> objects;
public:
    /**
     * @brief Construct a new game state dead object
     * 
     * @param window 
     * @param width 
     * @param height 
     * @param state_t 
     */
    game_state_dead(sf::RenderWindow & window, unsigned int width, unsigned int height, state & state_t);

    /**
     * @brief 
     * 
     */
    void draw() override;

    /**
     * @brief 
     * 
     */
    void update() override;
};
#endif