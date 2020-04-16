#include "Pokemon.h"

class Battle {

public:
	static float damageCalc(Pokemon attacker, Pokemon *defender, Attack attack, bool *crit);
	
private:
	Battle() {}
	static float typeEffectiveness(Pokemon defender, Attack attack);

}; 
