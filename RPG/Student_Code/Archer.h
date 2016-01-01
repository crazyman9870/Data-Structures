#pragma once
#include "Fighter.h"
#include <string>
class Archer :
	public Fighter
{
public:
	Archer(void);
	~Archer(void);

	Archer(string n, int mhp, int str, int spd, int mp);

	int getDamage();
	bool useAbility();
	void reset();

private:
	int original_speed;
};