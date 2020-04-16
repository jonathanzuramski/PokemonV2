#ifndef _POKEMON_H
#define _POKEMON_H

#include <iostream> 
#include <string>
#include "Attack.h"


#define FIRE 0
#define WATER 1
#define GRASS 2
#define ELECTRIC 3
#define NORMAL 4


class Pokemon {

protected:
	string *name;
	string *frontSprite;
	string* rearSprite;
	
	float health, maxHealth, attackPower, defence, xp,
		specialAttack, specialDefense, speed, level; 

	int type, baseHP, baseAttackPow, baseDef, baseSpecAttk,
		baseSpecDef, baseSpeed;

	Attack attacks[4];

private:  
	float statForumla(float baseStat);
	float healthStat(float baseStat);
	

public:
	//getters
	string getName();
	string returnType();
	string getFront();
	string getRear();
	Attack* getAttacks(); 

	
	float getMaxHealth();
	float getHealth(); 
	float getAttackPower();
	float getSpecialAttackPower();
	float getDefence(); 
	float getSpecialDefense();
	float getLevel(); 
	float getXP();
	int getType();
	void levelUp();
	
	//setters
	void setHealth(float health);
	void setAttackPower(float attackPower);
	void setSpecialAttackPower(float spAttackPower);
	void setSpecialDefense(float spDefense);
	void addXP(); 
	void printAttacks();

	//functions 
	int isDead();
	void restoreHealth();
	void printStats();

	
};
#endif