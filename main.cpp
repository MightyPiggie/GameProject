#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "gamestates.hpp"
#include "drawable.hpp"
#include "simplefunction.hpp"
#include "window_part.hpp"
#include "player.hpp"
#include "buttons.hpp"
#include "obstacle.hpp"
#include "menu.hpp"
#include "sprite_factory.hpp"
#include "game_screen.hpp"


int main( int argc, char *argv[] ){

	gamewindow game;
	game.run();
}