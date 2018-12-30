#pragma once

#include "character.h"

using namespace std;

class enemy : public character {	//enemy constructor uses the already created character constructor
public:
	enemy(string enteredName, string enteredDescription) : character(enteredName, enteredDescription) {};
	void fight(character *other);
	bool isAlive();
	void setStats(int level);
};