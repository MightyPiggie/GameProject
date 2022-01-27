#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

#include "drawable.hpp"
#include "init_game.hpp"
#include "game_settings.hpp"
#include "game_states.hpp"
#include "sprite_factory.hpp"
#include "object.hpp"
#include "line.hpp"

class player : public object {
protected:
    float movement_speed = 60;
    unsigned int window_width;
    unsigned int window_height;
    game_settings & game_setting;
    state & state_t;
    std::vector<std::string> unlocked_players = read_values(game_setting);

public:
    player(sf::RenderWindow & window,
            sf::Vector2f position,
            sf::Vector2f size,
            game_settings & game_setting,
            state & state_t);

    void draw() override;
    void move(std::vector<std::shared_ptr<object>>& gameobjects);
    void check_dead(const std::vector<std::shared_ptr<object>>& gameobjects, const std::shared_ptr<line>& lineobjects);
    sf::FloatRect getbounds() override;
    void update() override;

};

#endif