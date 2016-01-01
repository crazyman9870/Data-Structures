/*
 * Stack.h
 *
 *  Created on: May 27, 2014
 *      Author: aconstan
 */

#ifndef STACK_H_
#define STACK_H_

#include "LinkedList.h"

#include <stack>

using namespace std;

class Stack
{
private:

	LinkedList<int> LLs;

public:
	Stack();
	virtual ~Stack();

	//bool search_s(stack<int> pile, int car);

	void add_car(int cur_car);

	int remove_car();

	int show_top();

	int size();

	bool search_stack(int cur_car);

	//===================================================================================================

};

#endif
