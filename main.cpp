#include "game_screen.hpp"
#include <iostream>
#include <SFML/Audio.hpp>


int main( int argc, char *argv[] ){
    /// Hier hoor ik geluid. Wordt die na de game_screen game gezet in de main hoor ik geen geluid.
    /// Zet ik de zelfde instellingen in de game_state_menu.cpp bij de button functie hoor ik ook niks.
    sf::SoundBuffer buffer;
    sf::Sound sound;
    if(!buffer.loadFromFile("res/sounds/menu-window-title.wav")){
        std::cout << "Error\n";
    }
    sound.setBuffer(buffer);
    std::cout << "speel geluid\n";
    sound.play();

	game_screen game;
	game.run();
}

