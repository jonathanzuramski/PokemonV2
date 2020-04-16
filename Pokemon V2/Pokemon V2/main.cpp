#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "PokemonGUI.h"
#include "Pokemon.h"
#include "Squirtle.h"
#include "Pikachu.h"
#include "Charmander.h"
#include "Bulbasaur.h"


int main() {
	
	PokemonGUI game; 
	sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(720, 480), "Pokemon: Ruby Red", sf::Style::Close);

	game.drawBattleGUI( *window, Bulbasaur(), Pikachu()); 
	
	return 0;
}

