#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include "simplefunction.hpp"
#include "game_screen.hpp"

int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	gamewindow game;
	game.loop();


	std::cout << "Terminating application\n";
	return 0;
}

