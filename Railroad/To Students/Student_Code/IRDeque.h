/*
 * IRDeque.h
 *
 *  Created on: May 27, 2014
 *      Author: aconstan
 */

#ifndef IRDEQUE_H_
#define IRDEQUE_H_

#include "LinkedList.h"

using namespace std;

class IRDeque
{
private:

	LinkedList<int> LLIR;

public:
	IRDeque();
	virtual ~IRDeque();

	void insert_left(int cur_car);

	int remove_right();

	int remove_left();

	int show_left();

	int show_right();

	int size();

	bool search_IRdeque(int cur_car);

};

#endif /* IRDEQUE_H_ */
