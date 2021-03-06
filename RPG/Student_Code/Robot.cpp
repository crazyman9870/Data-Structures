#include "Robot.h"
#include <string>
#include <cmath>


Robot::Robot(void)
{
}

Robot::~Robot(void)
{
}

Robot::Robot(string n, int mhp, int strn, int spd, int mp)
	:Fighter (n, mhp, strn, spd, mp)
{
	max_elec = mp * 2;
	elec = max_elec;
	bonus_damage = 0;
}

int Robot::getDamage()
{
	int damage;
	if (bonus_damage == 0)
	{
		damage = strength;
	}
	else
	{
		damage = strength + bonus_damage;
	}
	bonus_damage = 0;
	return damage;
}

bool Robot::useAbility()
{
	if (elec >= ROBOT_ABILITY_COST)
	{
		bonus_damage = (strength * (pow(elec/max_elec,4.0)));
		elec = elec - ROBOT_ABILITY_COST;
		return true;
	}
	
		return false;
	
}

void Robot::reset()
{
	bonus_damage = 0;
	elec = max_elec;
	hp = max_hp;
}
