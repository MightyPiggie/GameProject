#include <iostream>
#include "drawable.hpp"
#include "obstacle.hpp"
#include <SFML/Graphics.hpp>
int main() {
    sf::RenderWindow window{ sf::VideoMode{ 1000, 500 }, "SFML window" };
    obstacle stone{window, sf::Vector2f{ 100, 105}, sf::Vector2f{30, 200} };
    sf::RectangleShape stone2;
    stone2.setSize(sf::Vector2f{30, 200});
    stone2.setPosition(sf::Vector2f{ 100, 105});
    std::cout << stone.overlaps(stone2.getGlobalBounds());
}