#pragma once
#include "Fighter.h"
#include <string>
class Robot :
	public Fighter
{
public:
	Robot(void);
	~Robot(void);

	Robot(string n, int mhp, int str, int spd, int mp);

	int getDamage();
	bool useAbility();
	void reset();

private:
	double max_elec;
	double elec;
	double bonus_damage;
};