
#include "Attack.h"

Attack::Attack(string name, float power, int type, bool specialMove) {
	this->name = (new string(name)); 
	this->power = power; 
	this->type = type; 
	this->specialMove = specialMove;
}

Attack::Attack() {
	this->name = NULL; 
	this->power = 0; 
	this->type = -1;
	this->specialMove = false;
}

float Attack::getPower(){
	return this->power; 
}

bool Attack::getSpecialType() {
	return this->specialMove;
}

int Attack::getType() {
	return this->type; 
}

string Attack::getName() {
	return *(this->name); 
}