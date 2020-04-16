#include "Pokemon.h"
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <string>
using namespace std;

#define DEAD 0
#define ALIVE -1

void Pokemon::printAttacks() {

	cout << "\n   1. " << this->attacks[0].getName() << "   2. " << this->attacks[1].getName()
		<< "\n   3. " << this->attacks[2].getName() << "   4. " << this->attacks[3].getName() << endl;

}

void Pokemon::printStats() {
	
	cout << "   " + *(this->name) << endl;
	cout << "   Health: " << this->health << endl;
	cout << "   Attack Power: " << this->attackPower << endl;
	cout << "   Type:" << this->returnType() << endl;
	cout << "   Special Attack: " << this->specialAttack << endl;
	cout << "   Special Defence: " << this->specialDefense << endl;
	cout << "   Speed: " << this->speed << endl;
	cout << "   Level: " << this->level << endl;
}

string Pokemon::getName() {
	return *(this->name); 
}

string Pokemon::getFront() {
	return *(this->frontSprite);
}

string Pokemon::getRear() {
	return *(this->rearSprite);
}


Attack* Pokemon::getAttacks() {
	return (this->attacks); 
}

float Pokemon::getHealth() {
	return this->health;
}

float Pokemon::getMaxHealth() {
	return this->maxHealth;
}

float Pokemon::getDefence() {
	return this->defence; 
}

void Pokemon::setHealth(float health) {
	if (this->health - health > 0) {
		this->health -= health;
	} else {
		this->health = 0;
	}
}

float Pokemon::getAttackPower() {
	return this->attackPower;
}

void Pokemon::setAttackPower(float attackPower) {
	this->attackPower = attackPower;
}

float Pokemon::getSpecialAttackPower() {
	return this->specialAttack;
}

void Pokemon::setSpecialAttackPower(float spAttackPower) {
	this->specialAttack = spAttackPower;
}

float Pokemon::getSpecialDefense() {
	return this->specialDefense;
}

void Pokemon::setSpecialDefense(float spDefense) {
	this->specialDefense = specialDefense;
}

int Pokemon::getType() {
	return this->type;
}

float Pokemon::getLevel() {
	return this->level;
}

void Pokemon::levelUp() {
	this->level = level + 1; 

	//adjust stats after leveling
	this->maxHealth = healthStat(this->baseHP);
	this->attackPower = statForumla(this->baseAttackPow);
	this->defence = statForumla(this->baseDef);
	this->specialAttack = statForumla(this->baseSpecAttk);
	this->specialDefense = statForumla(this->baseSpecDef);
	this->speed = statForumla(this->baseSpeed);

	this->restoreHealth();

}

float Pokemon::statForumla(float baseStat) {
	srand((unsigned int)time(NULL));
	int IV = rand() % 16;
	int EV = rand() % 4;

	float base = floor(floor((2 * baseStat + IV + EV) * this->level / 100 + 5) * 1);

	return base;
}

float Pokemon::healthStat(float baseStat) {
	srand((unsigned int)time(NULL));
	int IV = rand() % 16; 
	int EV = rand() % 4;

	float base = floor((2 * baseStat + IV + EV) * this->level / 100 + this->level + 10);

	return base;
}

float Pokemon::getXP() {
	return this->xp;
}

void Pokemon::addXP() {
	
	this->xp += (pow((4 * this->level), 3)) / 5;
	
	if(xp >= (10 *((pow(level,2))*log(level)))){
		this->levelUp();
	}

}

int Pokemon::isDead() {

	if(this->health == 0) {
		return DEAD;
	} 
	return ALIVE;
}

void Pokemon::restoreHealth() {
	this->health = this->maxHealth;
}

string Pokemon::returnType() {

	if(this->type == ELECTRIC) {
		return " Electric ";
	} else if (this->type == WATER) {
		return " Water ";
	} else if (this->type == FIRE){
		return " Fire ";
	} else if (this->type == NORMAL) {
		return " Normal ";
	} else {
		return " Grass ";
	}
}



