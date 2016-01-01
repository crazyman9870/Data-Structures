#include "Arena.h"
//#include "Fighter.h" /*?*/
#include "Robot.h"
#include "Archer.h"
#include "Cleric.h"
#include <sstream>


Arena::Arena(void)
{
}


Arena::~Arena(void)
{
}

int search (vector<FighterInterface*> list, string to_find)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (to_find == list[i]->getName())
		{
			return i;
		}
	}
	return -1;
}

void remove_fxn (vector<FighterInterface*>& list, int to_be_removed)
{
	for (int i = to_be_removed + 1; i < list.size(); i++)
	{
		list[i - 1] = list[i];	
	}
	list.pop_back();
}


bool Arena::addFighter(string info)
{
	string s1;
	stringstream test;
	test << info;
	int count = 2;
	test >> s1 >> s1;
	while(test >> s1) 
	{
		for(int i = 0; i < s1.length(); i++)
		{
			if(!isdigit(s1[i]))
				return false;
		}
		count++;
	}
	if(count != 6)
		return false;

	string name;
	string type;
	int max_hp;
	int strength;
	int speed;
	int magic;
	stringstream ss;
	ss << info;
	ss >> name >> type >> max_hp >> strength >> speed >> magic;

	if (max_hp < 1)
		return false;
	if (strength < 1)
		return false;
	if (speed < 1)
		return false;
	if (magic < 1)
		return false;

	//string name = name;
	

	int found = 0;
	
	found = search(list, name);

	if (found != -1)
	{
		return false;
	}

	if (type == "R")
	{
		Fighter* p = new Robot(name, max_hp, strength, speed, magic);
		list.push_back(p);
	}
	else if (type == "A")
	{
		Fighter* p = new Archer(name, max_hp, strength, speed, magic);
		list.push_back(p);
	}
	else if (type == "C")
	{
		Fighter* p = new Cleric(name, max_hp, strength, speed, magic);
		list.push_back(p);
	}
	else
	{
		return false;
	}
	return true;

}

bool Arena::removeFighter(string name)
{
	int found = 0;
	found = search(list, name);
	if ( found == -1)
	{
		return false;
	}
	else
	{
		remove_fxn(list, found);
		return true;
	}
}

FighterInterface* Arena::getFighter(string name)
{
	int found = 0;
	found = search(list, name);
	if (found != -1)
	{
		return list[found];
	}
	return NULL;
}

int Arena::getSize()
{
	return list.size();
}