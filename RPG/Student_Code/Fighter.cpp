
#include "Fighter.h"
#include <string>
#include <vector>

Fighter::Fighter(void)
{
}


Fighter::~Fighter(void)
{
}

Fighter::Fighter(string n, int mhp, int str, int spd, int mp)
{
	name = n;
	max_hp = mhp;
	strength = str;
	speed = spd;
	magic = mp;
}

string Fighter::getName()
{
	return name;
}
int Fighter::getMaximumHP()
{
	return max_hp;
}
int Fighter::getCurrentHP()
{
	return hp;
}
int Fighter::getStrength()
{
	return strength;
}
int Fighter::getSpeed()
{
	return speed;
}
int Fighter::getMagic()
{
	return magic;
}
void Fighter::takeDamage(int damage)
{
	damage = (damage - (speed / 4));
	if (damage < 1)
	{
		damage = 1;
	}
	hp -=  damage;
}
void Fighter::regenerate()
{
	double regen = strength / 6;
	if (regen < 1)
	{
		hp++;
	}
	hp += regen;
	if (hp > max_hp)
	{
		hp = max_hp;
	}
}