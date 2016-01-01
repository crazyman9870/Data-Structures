#pragma once
#include "Fighter.h"
#include <string>

class Cleric :
	public Fighter
{
public:
	Cleric(void);
	~Cleric(void);

	Cleric(string n, int mhp, int str, int spd, int mp);

	int getDamage();
	bool useAbility();
	void reset();
	void regenerate(); //Special to the cleric class


	int getMana();
	int getMaxMana();

private:
	int max_mana;
	int mana;
};