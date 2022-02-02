#include "player.hpp"

#include <iostream>

/// Player constructor. maakt de player aan en heeft basis informatie om mee te beginnen. Dit wordt geupdate wanneer je speelt.
player::player(sf::RenderWindow & window,
        sf::Vector2f position,
        sf::Vector2f size,
        game_settings & game_setting,
        state & state_t,
        sound_class & the_sound_class_player):
    object(window, position, size, NON_OBSTACLE, "chicken_player"),
    game_setting(game_setting),
    state_t(state_t),
    the_sound_class_player(the_sound_class_player)
{
//    dead.setBuffer(the_sound_class_player.get_sound_buffer("dead"));
    move_sound.setBuffer(the_sound_class_player.get_sound_buffer("move_sound"));
    pick_up_coin_sound.setBuffer(the_sound_class_player.get_sound_buffer("pick_up_coin"));
}
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
void player::move(std::vector<std::shared_ptr<builder_object>>& gameobjects) {
    if (position.x != float(window.getSize().x) / 4 && (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))){
        restore_position();
        game_setting.started = true;
        position += sf::Vector2f{-movement_speed, 0};
        function_for_move(gameobjects, sf::Vector2f{movement_speed, 0});
    } else if (position.x != float(window.getSize().x) * 3 / 4 - movement_speed &&
            (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
        restore_position();
        game_setting.started = true;
        position += sf::Vector2f{movement_speed, 0};
        function_for_move(gameobjects, sf::Vector2f{-movement_speed, 0});
    } else if (position.y > 30 && (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
        restore_position();
        game_setting.started = true;
        bool score = true;
        position += sf::Vector2f{0, -movement_speed};
        function_for_move_score(gameobjects, sf::Vector2f{0, movement_speed}, score, false);
        if (score) { game_setting.score++; }
    } else if (position.y != float(window_height) - movement_speed && (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {
        restore_position();
        game_setting.started = true;
        bool score = true;
        position += sf::Vector2f{0, +movement_speed};
        function_for_move_score(gameobjects, sf::Vector2f{0, -movement_speed}, score, false);
    }
}

/// Checkt of de player tegen iets dodelijks is aangelopen. Dit zijn autos, trainen en water.
void player::check_dead(const std::vector<std::shared_ptr<object>>& gameobjects, const std::shared_ptr<builder_object>& lineobjects) {
    if(position.y >= window.getSize().y || position.x + size.x < window.getSize().x/4 || position.x >= window.getSize().x*3/4){
        state_t = DEAD;
        return;
    }
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

    overlap = false;
    if (lineobjects->object_state == DEADLY) {
        for (auto &object1: gameobjects) {
            if (object1->object_state == FLOATING && this->overlaps(lineobjects)) {
                if(this->overlaps(object1)) {
                    if(object1->get_speed() != 0){
                        bool dir = object1->get_direction(); // 1 is naar rechts, 0 naar links;
                        dir ? position.x += object1->get_speed() : position.x -= object1->get_speed();
                    }
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
sf::FloatRect player::getbounds(){
    return sprite.getGlobalBounds();
}

void player::restore_position(){
    if(int(position.x) % 60 == 0){
        return;
    }else if(int(position.x) % 60 <= 30){
        position.x -= int(position.x) % 60;
    }else{
        position.x += 60 - (int(position.x) % 60);
    }
}

void player::function_for_move(std::vector<std::shared_ptr<builder_object>>& gameobjects, sf::Vector2f new_position){
    for(unsigned int index = 0; index < gameobjects.size(); index++) {
        for(unsigned int index_line_objects = 0; index_line_objects < gameobjects[index]->objects_for_level.size(); index_line_objects++){
            if(gameobjects[index]->objects_for_level[index_line_objects]->object_state == OBSTACLE){
                if (this->overlaps(gameobjects[index]->objects_for_level[index_line_objects])) {
                    position += new_position;
                    return;
                }
            }
            if(gameobjects[index]->objects_for_level[index_line_objects]->object_state == COIN) {
                if (this->overlaps(gameobjects[index]->objects_for_level[index_line_objects])) {
                    game_setting.coins ++;
                    if(game_setting.sound){pick_up_coin_sound.play();}
                    gameobjects[index]->objects_for_level.erase (gameobjects[index]->objects_for_level.begin() + index_line_objects);
                }
            }
        }
    }
    if(game_setting.sound){move_sound.play();}
}


void player::function_for_move_score(std::vector<std::shared_ptr<builder_object>>& gameobjects, sf::Vector2f new_position, bool & score, bool new_score_bool){
    for(unsigned int index = 0; index < gameobjects.size(); index++) {
        for(unsigned int index_line_objects = 0; index_line_objects < gameobjects[index]->objects_for_level.size(); index_line_objects++){
            if(gameobjects[index]->objects_for_level[index_line_objects]->object_state == OBSTACLE){
                if (this->overlaps(gameobjects[index]->objects_for_level[index_line_objects])) {
                    position += new_position;
                    score = new_score_bool;
                    return;
                }
            }
            if(gameobjects[index]->objects_for_level[index_line_objects]->object_state == COIN) {
                if (this->overlaps(gameobjects[index]->objects_for_level[index_line_objects])) {
                    game_setting.coins ++;
                    if(game_setting.sound){pick_up_coin_sound.play();}
                    gameobjects[index]->objects_for_level.erase (gameobjects[index]->objects_for_level.begin() + index_line_objects);
                }
            }
        }
    }
    if(game_setting.sound){move_sound.play();}
}
