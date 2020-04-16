#include "PokemonGUI.h"
#include "Attack.h"
#include "Battle.h";

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>



using namespace std; 
using namespace sf;

void PokemonGUI::drawBattleGUI(sf::RenderWindow& window, Pokemon yourPokemon, Pokemon enemy) {

	//Music: intialize battle music and loop!
	/*Music music;
	music.openFromFile("Audio\\bgm\\Battle.wav");
	music.play();
	music.setLoop(true);
    */

//Load Textures, and Fonts
	Texture backgroundTexture;
	Font font;
	font.loadFromFile("Pokemon Classic.ttf");
	backgroundTexture.loadFromFile("My Graphics\\background.png");

	//set background accordingly 
	RectangleShape background(Vector2f(720.0f, 480.0f));
	background.setTexture(&backgroundTexture);
	
	//Create Rectangle Selector for attacks 
	RectangleShape selector(Vector2f(200, 25));

	//possible selector positions for attacks
	Vector2f BottomLeft(20, 415), UpperLeft(20, 375);
	Vector2f BottomRight(250, 415), UpperRight(250, 375);
	
	selector.setPosition(BottomLeft);
	selector.setOutlineColor(Color::Red);
	selector.setFillColor(Color::Transparent);
	selector.setOutlineThickness(3);

	//loads pokemon attacks to displays
	Text yourAttacks[4];
	Attack *attacks = yourPokemon.getAttacks();

	//intializes attacks into strings
	for (int i = 0; i < 4; i++) {
		yourAttacks[i].setString(attacks[i].getName());
		yourAttacks[i].setFont(font);
		yourAttacks[i].setCharacterSize(15);
		yourAttacks[i].setFillColor(Color::Black);
	}

	//positions for attack to be displayed 
	//BottomLeft Attack
	yourAttacks[0].setPosition(Vector2f(30, 420));
	//UpperLeft Attack
	yourAttacks[1].setPosition(Vector2f(30, 380));
	//BottomRight Attack
	yourAttacks[2].setPosition(Vector2f(260, 420));
	//UpperRight Attack
	yourAttacks[3].setPosition(Vector2f(260, 380));


	//Loading character sprites 
	Texture me, opponent;
	me.loadFromFile(yourPokemon.getRear());
	opponent.loadFromFile(enemy.getFront());
	Sprite yourSprite(me), enemySprite(opponent);

	//resizing sprites for screen size
	yourSprite.setScale(3, 3);
	enemySprite.setScale(4, 4);


	//position sprites for battle!
	yourSprite.setPosition(Vector2f(85.0f, 168.0f));
	enemySprite.setPosition(Vector2f(380.0f, 0.0f));

	Attack selectedAttack = attacks[0];

	//while window is open goes through and selects proper attack
	//and moves the selector on the screen to each attack position
	float lastHealth = yourPokemon.getMaxHealth(), enemyLastHealth = enemy.getMaxHealth(); 
	bool firstDraw = true; 

	while (window.isOpen()) {

		Event battle;
		bool isCrit = false;
		float currentHealth = yourPokemon.getHealth(), enemyCurrentHealth = yourPokemon.getHealth();
		

		while (window.pollEvent(battle)) {


			if (battle.type == battle.Closed) {
				window.close();
			}

			if (battle.type == Event::KeyPressed) {

				if (battle.key.code == Keyboard::Up) {
					if ((PokemonGUI::compareVectors(selector.getPosition(), BottomLeft) == 0)) {
						selectedAttack = attacks[1];
						selector.setPosition(UpperLeft);
					}
					else if ((PokemonGUI::compareVectors(selector.getPosition(), BottomRight) == 0)) {
						selectedAttack = attacks[3];
						selector.setPosition(UpperRight);
					}
				}
				else if (battle.key.code == Keyboard::Left) {
					if ((PokemonGUI::compareVectors(selector.getPosition(), UpperRight) == 0)) {
						selectedAttack = attacks[1];
						selector.setPosition(UpperLeft);
					}
					else if ((PokemonGUI::compareVectors(selector.getPosition(), BottomRight) == 0)) {
						selectedAttack = attacks[0];
						selector.setPosition(BottomLeft);
					}

				}
				else if (battle.key.code == Keyboard::Right) {
					if ((PokemonGUI::compareVectors(selector.getPosition(), BottomLeft) == 0)) {
						selectedAttack = attacks[2];
						selector.setPosition(BottomRight);
					}
					else if ((PokemonGUI::compareVectors(selector.getPosition(), UpperLeft) == 0)) {
						selectedAttack = attacks[3];
						selector.setPosition(UpperRight);
					}
				}
				else if (battle.key.code == Keyboard::Down) {
					if ((PokemonGUI::compareVectors(selector.getPosition(), UpperLeft) == 0)) {
						selectedAttack = attacks[0];
						selector.setPosition(BottomLeft);
					}
					else if ((PokemonGUI::compareVectors(selector.getPosition(), UpperRight) == 0)) {
						selectedAttack = attacks[2];
						selector.setPosition(BottomRight);
					}
				}
				else if (battle.key.code == Keyboard::Enter) {
					Battle::damageCalc(yourPokemon, &enemy, selectedAttack, &isCrit);
					Battle::damageCalc(enemy, &yourPokemon, enemy.getAttacks()[rand() % 4], &isCrit);
				}
			}
		}
		

		//display sprites to window
		window.clear();
		window.draw(background);
		window.draw(selector);
		window.draw(enemySprite);
		window.draw(yourSprite);
		window.draw(yourAttacks[0]);
		window.draw(yourAttacks[1]);
		window.draw(yourAttacks[2]);
		window.draw(yourAttacks[3]);
		drawHealthBars(window, yourPokemon, enemy);
		window.display();

	}
}

int PokemonGUI::drawHealthBars(RenderWindow& window, Pokemon me, Pokemon enemy) {
	
	float myHealth, myMaxHP, enemyHealth, enemyMaxHP; 
	float enemyHealthRatio, meHealthRatio;
	Font font;
	Texture healthGUI;
	healthGUI.loadFromFile("My Graphics\\HealthBar.png");
	font.loadFromFile("Pokemon Classic.ttf");

	//represents health
	RectangleShape red(Vector2f(140, 30));
	RectangleShape white(Vector2f(150, 30));
	RectangleShape red2(Vector2f(200, 30));
	RectangleShape white2(Vector2f(200, 30));

	white.setFillColor(Color::White);
	red.setFillColor(Color::Green);
	white.setPosition(Vector2f(100, 30));
	red.setPosition(Vector2f(100, 30));
	white2.setFillColor(Color::White);
	red2.setFillColor(Color::Green);
	white2.setPosition(Vector2f(470, 270));
	red2.setPosition(Vector2f(470, 270));

	Sprite myHealthBox(healthGUI), enemyHealthBox(healthGUI);
	myHealthBox.setPosition(370.0f, 225.0f);
	enemyHealthBox.setPosition(30.0f, 10.0f);
	myHealthBox.setScale(0.7f, 0.7f);
	enemyHealthBox.setScale(0.5, 0.5);


	myHealth = me.getHealth();
	myMaxHP = me.getMaxHealth(); 
	enemyHealth = enemy.getHealth();
	enemyMaxHP = enemy.getMaxHealth();

	Text myName(me.getName(), font, 20); 
	Text enemyName(enemy.getName(), font, 15);  
	myName.setFillColor(Color::Black);
	enemyName.setFillColor(Color::Black);
	myName.setPosition(420, 235);
	enemyName.setPosition(50, 18);


	enemyHealthRatio = enemyHealth / enemyMaxHP;
	meHealthRatio = myHealth / myMaxHP;

	if (meHealthRatio < .4) {
		red2.setFillColor(Color::Red);
	}
	if (enemyHealthRatio < .4) {
		red.setFillColor(Color::Red);
	}

	red.setScale(enemyHealth / enemyMaxHP, 1);
	
	
	red2.setScale(myHealth / myMaxHP, 1);
	

	window.draw(white);
	window.draw(red);
	window.draw(white2);
	window.draw(red2);
	window.draw(enemyHealthBox);
	window.draw(myHealthBox);
	window.draw(myName);
	window.draw(enemyName);

	return 0;
}

void PokemonGUI::drawText(sf::RenderWindow& window, Pokemon pokemon) {	
}

int PokemonGUI::compareVectors(sf::Vector2f v1, sf::Vector2f v2) {
	if (v1.x == v2.x && v1.y == v2.y) {
		return 0; 
	} else {
		return -1;
	}
	 
}


