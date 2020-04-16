#include "Battle.h"
#include <time.h>
#include <string>

#define INEFFECTIVE 0.00
#define NOT_VERY_EFFECTIVE 0.5
#define NORMALLY_EFFECTIVE 1
#define SUPER_EFFECTIVE 2

float Battle::damageCalc(Pokemon attacker, Pokemon *defender, Attack attack, bool *crit) {

	float attackPower = 0, def = 0, power = 0, level = 0;
	float mainDamage = 0, modifiers = 0, totalDamage = 0;
	float critical = 0, random = 0, STAB = 0, typeEffectiveness = 0; 

	//random modifier for damage
	random = (float)(rand() % 16 + 85.0);
	random = (float)(random / 100);

	// doubling the damage
	srand((unsigned int)time(NULL));
	if ((rand() % 10000) < 625) {
		critical = 2.0;
		*crit = true;
	} else {
		critical = 1.0;
		*crit = false; 
	}

	//if Pokemon matches attackType damage is increased
	if (attack.getType() == attacker.getType()) {
		STAB = 1.5;
	}
	else {
		STAB = 1.0;
	}
	
	//uses Special Attack Power if move is a special attack
	if(attack.getSpecialType()) {
		attackPower = attacker.getSpecialAttackPower();
		def = defender->getSpecialDefense();
	} else {
		attackPower = attacker.getAttackPower();
		def = defender->getDefence();
	}
	level = attacker.getLevel();
	power = attack.getPower(); 
	typeEffectiveness = Battle::typeEffectiveness(*defender, attack);
	
	float step1, step2;

	step1 = ((2 * level) / 5) + 2;
	step2 = step1 * power * attackPower / def;
	mainDamage = step2 / 50 + 2;
	modifiers = critical * random * STAB * typeEffectiveness; 
	totalDamage = mainDamage * modifiers;

	defender->setHealth(totalDamage);
	return totalDamage; 
}



// determines attack types effectiveness on defending Pokemon
float Battle::typeEffectiveness(Pokemon defender, Attack attack) {

	int attackType, defenderType;

	attackType = attack.getType();
	defenderType = defender.getType();

	if (attackType == FIRE && defenderType == WATER) {
		return NOT_VERY_EFFECTIVE;

	}
	else if (attackType == GRASS && defenderType == WATER) {
		return SUPER_EFFECTIVE;

	}
	else if (attackType == WATER && defenderType == FIRE) {
		return SUPER_EFFECTIVE;

	}
	else if (attackType == ELECTRIC && defenderType == WATER) {
		return SUPER_EFFECTIVE;

	}
	else if (attackType == GRASS && defenderType == WATER) {
		return SUPER_EFFECTIVE;

	}
	else if (attackType == ELECTRIC && defenderType == ELECTRIC) {
		return NOT_VERY_EFFECTIVE;

	}
	else if (attackType == GRASS && defenderType == FIRE) {
		return NOT_VERY_EFFECTIVE;

	}
	else if (attackType == ELECTRIC && defenderType == GRASS) {
		return NOT_VERY_EFFECTIVE;

	}
	else if (attackType == WATER && defenderType == GRASS) {
		return NOT_VERY_EFFECTIVE;
	}
	else {
		return NORMALLY_EFFECTIVE;
	}
}