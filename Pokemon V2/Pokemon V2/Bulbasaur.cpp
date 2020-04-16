#include "Bulbasaur.h"
using namespace std;

 
Bulbasaur::Bulbasaur() {

	this->name = (new string("Bulbasaur"));
	this->frontSprite = (new string("sprites\\1.png"));
	this->rearSprite = (new string("sprites\\back\\1.png"));
	this->maxHealth = 45;
	this->health = 45;
	this->attackPower = 49;
	this->defence = 49;
	this->specialAttack = 65;
	this->specialDefense = 65;
	this->speed = 45;
	this->type = GRASS;
	this->level = 1;
	this->xp = 0;

	/* Base Stats for BulbaSaur */
	this->baseHP = 45;
	this->baseAttackPow = 49;
	this->baseDef = 49;
	this->baseSpecAttk = 65;
	this->baseSpecDef = 65;
	this->baseSpeed = 45;


	Attack tackle("Tackle", 40, NORMAL, false);
	Attack vineWhip("Vine Whip", 40, GRASS, true);
	Attack takeDown("Take Down", 60, NORMAL, false);
	Attack bubblebeam("Razor Leaf", 55, GRASS, true);

	this->attacks[0] = tackle;
	this->attacks[1] = vineWhip;
	this->attacks[2] = takeDown;
	this->attacks[3] = bubblebeam;

}
