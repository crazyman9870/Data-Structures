#include "Cleric.h"
#include <string>

Cleric::Cleric(void)
{
}

Cleric::~Cleric(void)
{
}

Cleric::Cleric(string n, int mhp, int strn, int spd, int mp)
	:Fighter (n, mhp, strn, spd, mp)
{
	max_mana = mp * 5;
	mana = max_mana;
}

int Cleric::getDamage()
{
	return magic;
}

void Cleric::regenerate()
{
	int regen = strength / 6;
	hp += regen;
	if (regen < 1)
	{
		hp++;
	}
	if (hp > max_hp)
	{
		hp = max_hp;
	}

	double regen_mana = magic / 5;
	mana += regen_mana;
	if (mana > max_mana)
	{
		mana = max_mana;
	}
}

int Cleric::getMana()
{
	return mana;
}

int Cleric::getMaxMana()
{
	return max_mana;
}

bool Cleric::useAbility()
{
	if (mana >= CLERIC_ABILITY_COST)
	{
		if (magic < 3)
		{
			hp++;
		}
		else
		{
			hp += (magic / 3);
			mana -= CLERIC_ABILITY_COST;
		}
		if (hp > max_hp)
		{
			hp = max_hp;
		}
		return true;
	}
	
		return false;
	
}

void Cleric::reset()
{
	hp = max_hp;
	mana = max_mana;
}