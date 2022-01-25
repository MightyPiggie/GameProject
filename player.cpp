#include "player.hpp"

void player::draw() {
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setPosition(position);
    window.draw(sprite);
}
//TODO check if this can be renamed to update
void player::move(std::vector<game_drawable *> &gameobjects) {
    if (position.x != float(window_width)/4 && sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        position += sf::Vector2f{-movement_speed, 0};
        for(auto &object : gameobjects) {
            if (object != this) {
                if(object->object_state == OBSTACLE){
                    if (this->overlaps(object)) {
                        position += sf::Vector2f{movement_speed, 0};
                    }
                }
            }
        }
    }
    else if (position.x != float(window_width)*3/4 - movement_speed && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        position += sf::Vector2f{movement_speed, 0};
        for(auto &object : gameobjects) {
            if (object != this) {
                if(object->object_state == OBSTACLE){
                    if (this->overlaps(object)) {
                        position += sf::Vector2f{-movement_speed, 0};
                    }
                }
            }
        }
    }
    else if(position.y != 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        game_setting.started = true;
        bool score = true;
        position += sf::Vector2f{0, -movement_speed};
        for(auto &object : gameobjects) {
            if (object != this || gameobjects.size() == 1) {
                if(object->object_state == OBSTACLE){
                    if (this->overlaps(object)) {
                        position += sf::Vector2f{0, movement_speed};
                        score = false;
                    }
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
            if (object != this) {
                if(object->object_state == OBSTACLE){
                    if (this->overlaps(object)) {
                        position += sf::Vector2f{0, -movement_speed};
                        score = false;
                    }
                }
            }
        }if(game_setting.score >= 1 && score){game_setting.score--; }
    }
}

void player::check_dead(std::vector<game_drawable *> &gameobjects) {
    for (auto &object: gameobjects) {
        if (object != this) {
            if (object->object_state == DEADLY) {
                if (this->overlaps(object)) {
                    state_t = DEAD;
                    break;
                }
            }
        }
    }
}



sf::FloatRect player::getbounds() {
    return sprite.getGlobalBounds();
}