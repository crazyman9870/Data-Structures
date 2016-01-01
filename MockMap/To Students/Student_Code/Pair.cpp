/*
 * Pair.cpp
 *
 *  Created on: Jun 11, 2014
 *      Author: aconstan
 */

#include "Pair.h"

using namespace std;

Pair::Pair(string prefix_in, string suffix_in)
{
	prefix = prefix_in;
	//suffix = suffix_in;
	slist.push_back(suffix_in);
}

Pair::~Pair()
{

}

string Pair::getPrefix()
{
	return prefix;
}

/*
string Pair::getSuffix()
{
	return suffix;
}
*/

vector<string> Pair::getSlist()
{
	return slist;
}



void Pair::printSlist()
{
	for (int i = 0; i < slist.size(); i++)
	{
		cout << "pos " << i << "\t" << slist[i] << endl;
	}
}


void Pair::addSlist(string input)
{
	slist.push_back(input);
}

string Pair::random()
{
	string random = slist[rand() % slist.size()];
	return random;
}

void Pair::clearSlist()
{
	for (int i = 0; i < slist.size(); i++)
	{
		{
				slist.pop_back();
		}
	}
}
