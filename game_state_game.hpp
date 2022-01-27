#ifndef GAME_STATE_GAME_HPP
#define GAME_STATE_GAME_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <map>
#include <string>

#include "drawable.hpp"
#include "window_part.hpp"
#include "label.hpp"
#include "sprite_factory.hpp"
#include "buttons.hpp"
#include "game_settings.hpp"
#include "level.hpp"


/// game_state_game class, heritage van drawable
class game_state_game : public drawable{
private:
    game_settings & gameSettings;
    state & state_t;
    unsigned int width;
    unsigned int height;
    std::vector<std::shared_ptr<label>> labels;
    std::vector<std::shared_ptr<drawable>> drawables;
    std::vector<std::shared_ptr<drawable>> drawables1;
    level level1;

public:
    game_state_game(sf::RenderWindow & window,
                    unsigned int width,
                    unsigned int height,
                    game_settings & gameSettings,
                    state & state_t);
//    ~game_state_game();
    sf::Texture screenshot_gamescreen;
    void draw() override;
    void update() override;
    void destructor();
    std::shared_ptr<game_state_game> operator= (std::shared_ptr<game_state_game> rhs){
        return rhs;
    }
};

#endif