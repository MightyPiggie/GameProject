#include "player.hpp"

#include <iostream>

player::player(sf::RenderWindow & window,
        sf::Vector2f position,
        sf::Vector2f size,
        game_settings & game_setting,
        state & state_t):
    object(window, position, size, NON_OBSTACLE, "chicken_player"),
    game_setting(game_setting),
    state_t(state_t)
{}

void player::draw() {
    sprite.setPosition(position);
    window.draw(sprite);
}

void player::update() {
    // if(filename != "res/sprites/"+game_setting.player+".png"){
       // spritename = ;
        texture.loadFromFile(sprite_factory::get_instance().filenames[game_setting.player]);
        sprite.setTexture(texture);
    // }
}
//TODO not checking line so won't die trough water
//TODO check if this can be renamed to update
void player::move(const std::vector<std::shared_ptr<object>>& gameobjects) {
    if (position.x != float(window_width)/4 && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        position += sf::Vector2f{-movement_speed, 0};
        for(auto &object : gameobjects) {
            if(object->object_state == OBSTACLE){
                if (this->overlaps(object)) {
                    position += sf::Vector2f{movement_speed, 0};
                }
            }
        }
    }
    else if (position.x != float(window_width)*3/4 - movement_speed && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        position += sf::Vector2f{movement_speed, 0};
        for(auto &object : gameobjects) {
            if(object->object_state == OBSTACLE){
                if (this->overlaps(object)) {
                    position += sf::Vector2f{-movement_speed, 0};
                }
            }
        }
    }
    else if(position.y != 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        game_setting.started = true;
        bool score = true;
        position += sf::Vector2f{0, -movement_speed};
        for(auto &object : gameobjects) {
            if(object->object_state == OBSTACLE){
                if (this->overlaps(object)) {
                    position += sf::Vector2f{0, movement_speed};
                    score = false;
                }
            }
        }
        //todo score ivm met objecten moet elke keer maar 1 omhoog gaan en niet hoevaak er objecten zijn
        if(score){game_setting.score++;}
    }
    else if(position.y != float(window_height) - movement_speed && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        bool score = true;
        position += sf::Vector2f{0, +movement_speed};
        for(auto &object : gameobjects) {
            if(object->object_state == OBSTACLE){
                if (this->overlaps(object)) {
                    position += sf::Vector2f{0, -movement_speed};
                    score = false;
                }
            }
        }if(game_setting.score >= 1 && score){game_setting.score--; }
    }
}

void player::check_dead(const std::vector<std::shared_ptr<object>>& gameobjects) {
    for (auto &object: gameobjects) {
        if (object->object_state == DEADLY) {
            for (auto &object1: gameobjects) {
                if (object1->object_state == FLOATING) {
                    if(this->overlaps(object1)) {
                        return;
                    }
                }
            }
            if (this->overlaps(object)) {
                state_t = DEAD;
                if(game_setting.score > game_setting.highscore) {
                    game_setting.highscore = game_setting.score;
                    save(unlocked_players, game_setting);
                }
                break;
            }
            break;
        }
    }
}



sf::FloatRect player::getbounds() {
    return sprite.getGlobalBounds();
}