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
     * @param window A reference to the window where everything is drawn on.
     * @param width The width of the screen.
     * @param height The height of the screen.
     * @param state_t A refence to the state of which the game is in. 
     * @param the_sound_class A reference to the sound_class object.
     */
    game_state_dead(sf::RenderWindow & window, unsigned int width, unsigned int height, state & state_t, sound_class & the_sound_class);
    
    /**
     * @brief The draw function will call all objects draw function
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
