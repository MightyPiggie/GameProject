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
    sound_class & the_sound_class_dead;
    std::vector<std::shared_ptr<drawable>> objects;

    sf::Sound click_sound;
public:
    game_state_dead(sf::RenderWindow & window, unsigned int width, unsigned int height, state & state_t, sound_class & the_sound_class);
    void draw() override;
    void update() override;
};
#endif