#include "Charmander.h"


Charmander::Charmander() {

	this->name = (new string("Charmander"));
	this->frontSprite = (new string("sprites\\4.png"));
	this->rearSprite = (new string("sprites\\back\\4.png"));
	this->maxHealth = 39;
	this->health = 39;
	this->attackPower = 52;
	this->defence = 43;
	this->specialAttack = 60;
	this->specialDefense = 50;
	this->speed = 65;
	this->type = FIRE;
	this->level = 1;
	this->xp = 0;

	/* Base Stats for Charmander */
	this->baseHP = 39;
	this->baseAttackPow = 52;
	this->baseDef = 43;
	this->baseSpecAttk = 60;
	this->baseSpecDef = 50;
	this->baseSpeed = 65;

	Attack scratch("Scratch", 40, NORMAL, false);
	Attack ember("Ember", 40, FIRE, true);
	Attack slash("Slash", 70, NORMAL, false);
	Attack flamethrower("Flamethrower", 90, FIRE, true);

	this->attacks[0] = scratch;
	this->attacks[1] = ember;
	this->attacks[2] = slash;
	this->attacks[3] = flamethrower;

}
