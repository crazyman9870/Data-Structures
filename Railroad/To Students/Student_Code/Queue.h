/*
 * Queue.h
 *
 *  Created on: May 27, 2014
 *      Author: aconstan
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "LinkedList.h"

#include <queue>

using namespace std;

class Queue
{
private:

	LinkedList<int> LLq;

public:
	Queue();
	virtual ~Queue();

//===================================================================================================

	void add_car(int cur_car);

	int remove_car();

	int show_front();

	int size();

	bool search_queue(int cur_car);

};



#endif /* QUEUE_H_ */
