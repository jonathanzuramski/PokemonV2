#pragma once
#include <string>
using namespace std; 

class Attack {

private:
	string *name; 
	float power; 
	int type;
	bool specialMove; 

public: 
	Attack();
	Attack(string name, float power, int type, bool specialMove); 
	string getName();
	int getType();
	float getPower(); 
	bool getSpecialType(); 
	

};
