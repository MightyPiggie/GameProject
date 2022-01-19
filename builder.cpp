#include "builder.hpp"
#include <iostream>
#include <random>

builder::builder(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f size, std::map<std::string , std::string> sprite_factory):
    game_drawable(window, position, size), sprite_factory(sprite_factory)
    {}

unsigned int builder::random_int_between_range(int min, int max) {
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased

    return uni(rng);

}

void builder::update() {
    ticks +=1;
    if(ticks == 60) {
        std::cout << sprites[random_int_between_range(0,5)] << std::endl;
        ticks = 0;
    }
}
