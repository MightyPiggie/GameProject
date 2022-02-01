#ifndef GAME_STATE_DEAD_HPP
#define GAME_STATE_DEAD_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "drawable.hpp"
#include "simple_functions.hpp"
#include "game_state_game.hpp"

/// game_state_dead class, heritage van drawable
class game_state_dead : public drawable{
private:
    state & state_t;
    sound_class & the_sound_class_dead;
    std::vector<std::shared_ptr<drawable>> objects;

    sf::Sound click_sound;
public:
    /**
     * @brief Construct a new game state dead object
     * 
     * @param window 
     * @param width 
     * @param height 
     * @param state_t 
     * @param the_sound_class 
     */
    game_state_dead(sf::RenderWindow & window, unsigned int width, unsigned int height, state & state_t, sound_class & the_sound_class);
    
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
