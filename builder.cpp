#include "builder.hpp"

#include <iostream>

builder::builder(sf::RenderWindow& window, std::map<std::string , std::string> sprite_factory):
    window(window),
    sprite_factory(sprite_factory),
    rng(rd())
{}

unsigned int builder::random_int_between_range(int min, int max) {
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased

    return uni(rng);
}

void builder::update() {
    ticks +=1;
    if(ticks == 60) {
        std::cout << sprites[random_int_between_range(0,4)] << std::endl;
        ticks = 0;
    }
}
