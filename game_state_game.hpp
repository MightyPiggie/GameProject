#ifndef GAME_STATE_GAME_HPP
#define GAME_STATE_GAME_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <string>

#include "drawable.hpp"
#include "game_settings.hpp"
#include "sprite_factory.hpp"
#include "builder_biome.hpp"
#include "sound_class.hpp"

/// game_state_game class, heritage van drawable
class game_state_game : public drawable{
private:
    game_settings & gameSettings;
    state & state_t;
    unsigned int width;
    unsigned int height;

    std::vector<std::shared_ptr<drawable>> drawables;
    builder_biome level1;
    sound_class & the_sound_class_ingame;
    std::shared_ptr<drawable> background;
    sf::Sound click_sound;
public:
    /**
     * @brief Construct a new game state game object
     * 
     * @param window A reference to the window where everything is drawn on.
     * @param width The width of the screen.
     * @param height The height of the screen.
     * @param gameSettings A reference to all game settings of the game.
     * @param state_t A refence to the state of which the game is in. 
     * @param sound_class A reference to the sound_class object.
     */
    game_state_game(sf::RenderWindow & window,
                    unsigned int width,
                    unsigned int height,
                    game_settings & gameSettings,
                    state & state_t,
                    sound_class & the_sound_class_ingame);

    /**
     * @brief The draw function will call all objects draw function. It will also call the levels draw function.
     * 
     */
    void draw() override;

    /**
     * @brief The update function will call all the objects update function.
     * 
     */
    void update() override;
};

#endif
