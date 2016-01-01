#pragma once
#include "FighterInterface.h"
#include <string>
class Fighter :
	public FighterInterface
{
public:
	Fighter(void);
	~Fighter(void);

	Fighter(string n, int mhp, int str, int spd, int mp);

	string getName();
	int getMaximumHP();
	int getCurrentHP();
	int getStrength();
	int getSpeed();
	int getMagic();
	virtual int getDamage() = 0;
	void takeDamage(int damage);
	virtual void reset() = 0;
	void regenerate();
	virtual bool useAbility() = 0;

protected:
	string name; 
	int max_hp;
	int hp;
	int strength;
	int speed;
	int magic;

};

