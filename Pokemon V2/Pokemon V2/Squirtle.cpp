#include "Squirtle.h"
#include "Pokemon.h"
using namespace std;


Squirtle::Squirtle() {

	this->name = (new string("Squirtle"));
	this->frontSprite = (new string("sprites\\7.png"));
	this->rearSprite = (new string("sprites\\back\\7.png"));
	this->maxHealth = 44;
	this->health = 44;
	this->attackPower = 48;
	this->defence = 65;
	this->specialAttack = 50;
	this->specialDefense = 64;
	this->speed = 43;
	this->type = WATER;
	this->level = 1;
	this->xp = 0;

	/* Base Stats for Squirtle */
	this->baseHP = 44;
	this->baseAttackPow = 48;
	this->baseDef = 65;
	this->baseSpecAttk = 50;
	this->baseSpecDef = 64;
	this->baseSpeed = 43;
	


	Attack tackle("Tackle", 40, NORMAL, false);
	Attack bubble("Bite", 60, NORMAL, false);
	Attack watergun("Water Gun", 30, WATER, true);
	Attack bubblebeam("Bubble Beam", 65, WATER, true);

	this->attacks[0] = tackle;
	this->attacks[1] = bubble;
	this->attacks[2] = watergun;
	this->attacks[3] = bubblebeam;

}



