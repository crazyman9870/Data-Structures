/*
 * ORDeque.h
 *
 *  Created on: May 27, 2014
 *      Author: aconstan
 */

#ifndef ORDEQUE_H_
#define ORDEQUE_H_

using namespace std;

#include "LinkedList.h"

class ORDeque
{
private:

	LinkedList<int> LLOR;

public:
	ORDeque();
	virtual ~ORDeque();

	void insert_right(int cur_car);

	void insert_left(int cur_car);

	int remove_left();

	int show_left();

	int size();

	bool search_ORdeque(int cur_car);

};

#endif /* ORDEQUE_H_ */
