#pragma once
#include "Pokemon.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class PokemonGUI {

public:
	static void drawBattleGUI(sf::RenderWindow &window, Pokemon yourPokemon, Pokemon enemy);
	static int drawHealthBars(sf::RenderWindow& window, Pokemon me, Pokemon enemy);
	static void drawText(sf::RenderWindow& window, Pokemon pokemon); 
	
private:
	static int compareVectors(sf::Vector2f v1, sf::Vector2f v2);
};

