/*
 * Mimic.h
 *
 *  Created on: Jun 10, 2014
 *      Author: aconstan
 */

#ifndef MIMIC_H_
#define MIMIC_H_

#include "MimicInterface.h"
#include "Pair.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Mimic : public MimicInterface
{
private:
	string pre1;
	string pre2;
	string suff;
	vector<string> temp;
	vector<string> prefix;
	vector<Pair> map;
	vector<string> empty;
public:
	Mimic();
	virtual ~Mimic();

	void createMap(string input);

	vector<string> getSuffixList(string prefix);

	string generateText();

	//======================================================================

	int searchMap(vector<Pair> list, string find);

	bool search(vector<string> list, string find);

	void print_vec(vector<string> list);

	void print_map(vector<Pair> list);

	void break_string(string input);

	string bs2(string input);

	void clear_vector(vector<string> list);


	//list.erase(list.begin()+0);

};

#endif /* MIMIC_H_ */
