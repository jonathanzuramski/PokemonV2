#include "Pikachu.h"
#include "Pokemon.h"
using namespace std;


Pikachu::Pikachu() {

	this->name = new string("Pikachu");
	this->frontSprite = new string("sprites\\25.png");
	this->rearSprite = new string("sprites\\back\\25.png");
	this->maxHealth = 35;
	this->health = 35;
	this->attackPower = 55;
	this->defence = 40;
	this->specialAttack = 50;
	this->specialDefense = 50;
	this->speed = 90;
	this->type = ELECTRIC;
	this->level = 1;
	this->xp = 0;	 

	/* Base Stats for Pikachu */
	this->baseHP = 35;
	this->baseAttackPow = 55;
	this->baseDef = 40;
	this->baseSpecAttk = 50;
	this->baseSpecDef = 50;
	this->baseSpeed = 90;

	Attack thundershock("Thunder Shock", 40, ELECTRIC, true);
	Attack quickAttack("Quick Attack", 40, NORMAL, false);
	Attack doubleKick("Double Kick", 30, NORMAL, false);
	Attack thunderWave("Thunderbolt", 90, ELECTRIC, true);

	this->attacks[0] = thundershock;
	this->attacks[1] = quickAttack;
	this->attacks[2] = doubleKick;
	this->attacks[3] = thunderWave;

}


