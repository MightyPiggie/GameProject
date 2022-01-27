#include "object.hpp"

#include <stdlib.h>
#include <time.h>
#include <chrono>

#include "sprite_factory.hpp"


#include <iostream>
object::object(sf::RenderWindow & window, sf::Vector2f position , sf::Vector2f size, object_states object_state , std::string spritename):
    drawable(window, position, size),
    spritename(spritename),
    object_state(object_state)
{
    texture.loadFromFile(sprite_factory::get_instance().filenames[spritename]);
    sprite.setTexture(texture);
}



void object::draw() {
    sprite.setPosition(position);
    window.draw(sprite);
}

sf::FloatRect object::getbounds() {
    return obs.getGlobalBounds();
}

void object::lower(){
    position.y += 1;
}

moving_object::moving_object(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, object_states object_state, std::string filename, int change, bool direction, unsigned int speed):
    object(window, position, size, object_state, filename), change(change), direction(direction), speed(speed)
{}

unsigned int moving_object::random_int_between_range(int min, int max) {
    return rand() % (max+1);
}
void moving_object::update() {
    if(moving == false) {
        int tmp = random_int_between_range(0, change);
        if(tmp == 0) {
            moving = true;
        }
    }
    else if(moving == true) {
        if(direction == 1) {
            position.x += speed;
        }
        else if(direction == 0) {
            position.x -= speed;
        }
    }
}


