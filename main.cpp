#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "gamestates.hpp"
#include "drawable.hpp"
#include "simplefunction.hpp"
#include "player.hpp"
#include "buttons.hpp"
#include "menu.hpp"
#include "game_screen.hpp"

int main( int argc, char *argv[] ){
	gamewindow game;
	game.loop();
}
// int main() {
//     sf::RenderWindow window{ sf::VideoMode{ 1000, 500 }, "SFML window" };
//     obstacle stone{window, sf::Vector2f{ 100, 105}, sf::Vector2f{30, 200} };
//     sf::RectangleShape stone2;
//     stone2.setSize(sf::Vector2f{30, 200});
//     stone2.setPosition(sf::Vector2f{ 100, 105});
//     std::cout << stone.overlaps(stone2.getGlobalBounds());
// }
