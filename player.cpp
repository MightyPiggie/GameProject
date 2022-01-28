#include "player.hpp"

#include <iostream>

/// Player constructor. maakt de player aan en heeft basis informatie om mee te beginnen. Dit wordt geupdate wanneer je speelt.
player::player(sf::RenderWindow & window,
        sf::Vector2f position,
        sf::Vector2f size,
        game_settings & game_setting,
        state & state_t):
    object(window, position, size, NON_OBSTACLE, "chicken_player"),
    game_setting(game_setting),
    state_t(state_t)
{}
/// Player draw, dit is in een sprite
void player::draw() {
    sprite.setPosition(position);
    window.draw(sprite);
}

/// Player update. check of het nog steeds de juiste sprite is en deze dan inladen indien niet.
void player::update() {
    if(spritename != sprite_factory::get_instance().filenames[game_setting.player]){
        spritename = sprite_factory::get_instance().filenames[game_setting.player];
        texture.loadFromFile(spritename);
        sprite.setTexture(texture);
    }
}

/// Player move. Wordt gekeken naar keys en welk object dat dan is/van welke state. Op elk object een andere reactie.
void player::move(std::vector<std::shared_ptr<object>>& gameobjects) {
    if (position.x != float(window.getSize().x) / 4 && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        position += sf::Vector2f{-movement_speed, 0};
        for (unsigned int index = 0; index < gameobjects.size(); index++) {
            if (gameobjects[index]->object_state == OBSTACLE) {
                if (this->overlaps(gameobjects[index])) {
                    position += sf::Vector2f{movement_speed, 0};
                }
            }
            check_coin(gameobjects);
        }
    } else if (position.x != float(window.getSize().x) * 3 / 4 - movement_speed && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        position += sf::Vector2f{movement_speed, 0};
        for (unsigned int index = 0; index < gameobjects.size(); index++) {
            if (gameobjects[index]->object_state == OBSTACLE) {
                if (this->overlaps(gameobjects[index])) {
                    position += sf::Vector2f{-movement_speed, 0};
                }
            }
            check_coin(gameobjects);
        }
    } else if (position.y != 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        game_setting.started = true;
        bool score = true;
        position += sf::Vector2f{0, -movement_speed};
        for (unsigned int index = 0; index < gameobjects.size(); index++) {
            if (gameobjects[index]->object_state == OBSTACLE) {
                if (this->overlaps(gameobjects[index])) {
                    position += sf::Vector2f{0, movement_speed};
                    score = false;
                }
            }
            check_coin(gameobjects);
        }
        //todo score ivm met objecten moet elke keer maar 1 omhoog gaan en niet hoevaak er objecten zijn
        if (score) { game_setting.score++; }
    } else if (position.y != float(window_height) - movement_speed && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        bool score = true;
        position += sf::Vector2f{0, +movement_speed};
        for (unsigned int index = 0; index < gameobjects.size(); index++) {
            if (gameobjects[index]->object_state == OBSTACLE) {
                if (this->overlaps(gameobjects[index])) {
                    position += sf::Vector2f{0, -movement_speed};
                    score = false;
                }
            }
            check_coin(gameobjects);
        }
        if (game_setting.score >= 1 && score) { game_setting.score--; }
    }
}

void player::check_coin(std::vector<std::shared_ptr<object>> &gameobjects) {
    for (unsigned int index = 0; index < gameobjects.size(); index++) {
        if (gameobjects[index]->object_state == COIN) {
            if (this->overlaps(gameobjects[index])) {
                game_setting.coins++;
                gameobjects.erase(gameobjects.begin() + index);
            }
        }
    }
}

/// Checkt of de player tegen iets dodelijks is aangelopen. Dit zijn autos, trainen en water.
void player::check_dead(const std::vector<std::shared_ptr<object>>& gameobjects, const std::shared_ptr<builder_object>& lineobjects) {
    for (auto &object: gameobjects) {
        if (object->object_state == DEADLY) {
            for (auto &object1: gameobjects) {
                if (object1->object_state == DEADLY) {

                    if (this->overlaps(object1)) {
                        state_t = DEAD;
                        if(game_setting.score > game_setting.highscore) {
                            game_setting.highscore = game_setting.score;
                            save(unlocked_players, game_setting);
                        }
                        break;
                    }
                }}
            break;
        }
    }
    bool overlap = false;
    if (lineobjects->object_state == DEADLY) {
        for (auto &object1: gameobjects) {
            if (object1->object_state == FLOATING && this->overlaps(lineobjects)) {
                if(this->overlaps(object1)) {
                    overlap = true;
                    break;
                }
            }
        }
        if (overlap == false && this->overlaps(lineobjects)) {
            state_t = DEAD;
            if(game_setting.score > game_setting.highscore) {
                game_setting.highscore = game_setting.score;
                save(unlocked_players, game_setting);
            }
        }
    }
}


/// Krijg player global bounds.
sf::FloatRect player::getbounds() {
    return sprite.getGlobalBounds();
}