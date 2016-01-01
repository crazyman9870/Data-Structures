#pragma once
#include "ArenaInterface.h"
#include "Fighter.h"

#include <vector>
class Arena :
	public ArenaInterface
{
public:
	Arena(void);
	~Arena(void);

	bool addFighter(string info);
	bool removeFighter(string name);
	FighterInterface* getFighter(string name);
	int getSize();

private:
	vector<FighterInterface*> list;
};

