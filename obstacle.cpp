#include "obstacle.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>

obstacle::obstacle(sf::RenderWindow & window, sf::Vector2f position , sf::Vector2f size, object_states object_state , std::string filename):
    game_drawable(window, position, size, object_state), filename(filename)
{
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
    sprite.setPosition(position);
    window.draw(sprite);
}

void obstacle::draw() {
    sprite.setPosition(position);
    window.draw(sprite);
}

sf::FloatRect obstacle::getbounds() {
    return obs.getGlobalBounds();
}

obstacle_moving::obstacle_moving(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, object_states object_state, std::string filename, int change, bool direction):
    obstacle(window, position, size, object_state, filename), change(change), direction(direction)
{}

unsigned int obstacle_moving::random_int_between_range(int min, int max) {
    std::srand(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
    return rand() % (max+1);
}
void obstacle_moving::update() {
    if(moving == false) {
        int tmp = random_int_between_range(0, change);
        if(tmp == 0) {
            moving = true;
        }
    }
    else if(moving == true) {
        if(direction == 1) {
            position.x += 2;
        }
        else if(direction == 0) {
            position.x -= 2;
        }
    }
}


