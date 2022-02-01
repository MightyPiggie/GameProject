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
    game_state_game(sf::RenderWindow & window,
                    unsigned int width,
                    unsigned int height,
                    game_settings & gameSettings,
                    state & state_t,
                    sound_class & the_sound_class_ingame);
//    ~game_state_game();
    void draw() override;
    void update() override;
    std::shared_ptr<game_state_game> operator= (std::shared_ptr<game_state_game> rhs){
        return rhs;
    }
};

#endif
