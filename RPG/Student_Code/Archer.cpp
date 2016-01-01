#include "Archer.h"
#include <string>


Archer::Archer(void)
{
}

Archer::~Archer(void)
{
}

Archer::Archer(string n, int mhp, int strn, int spd, int mp)
	:Fighter (n, mhp, strn, spd, mp)
{
	original_speed = spd;
}

int Archer::getDamage()
{
	return speed; 
}

bool Archer::useAbility()
{
	speed++;
	return true;
}
void Archer::reset()
{
	speed = original_speed;
	hp = max_hp;
}

