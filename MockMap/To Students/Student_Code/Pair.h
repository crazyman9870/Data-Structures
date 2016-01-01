/*
 * Pair.h
 *
 *  Created on: Jun 11, 2014
 *      Author: aconstan
 */

#ifndef PAIR_H_
#define PAIR_H_

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

class Pair
{
private:
	string prefix;
	//string suffix;
	vector<string> slist;

public:
	Pair(string prefix_in, string suffix_in);
	virtual ~Pair();

	string getPrefix();

	//string getSuffix();

	vector<string> getSlist();

	void printSlist();

	void addSlist(string input);

	string random();

	void clearSlist();
};



#endif /* PAIR_H_ */
