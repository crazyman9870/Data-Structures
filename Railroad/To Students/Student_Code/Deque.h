/*
 * Deque.h
 *
 *  Created on: May 27, 2014
 *      Author: aconstan
 */

#ifndef DEQUE_H_
#define DEQUE_H_

#include "LinkedList.h"

#include <deque>

using namespace std;

class Deque
{
private:

	LinkedList<int> LLd;

public:
	Deque();
	virtual ~Deque();

//===================================================================================================

void insert_right(int cur_car);

void insert_left(int cur_car);

int remove_right();

int remove_left();

int show_left();

int show_right();

int size();

bool search_deque(int cur_car);

};


#endif /* DEQUE_H_ */
