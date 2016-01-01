/*
 * Queue.cpp
 *
 *  Created on: May 27, 2014
 *      Author: aconstan
 */

#include "Queue.h"

using namespace std;

Queue::Queue()
{

}

Queue::~Queue()
{

}

//Extra Fxns=============================================================================================

void Queue::add_car(int cur_car)
{
	LLq.insertTail(cur_car);
}

int Queue::remove_car()
{
	int front = LLq.at(0);
	LLq.remove(LLq.at(0));
	return front;
}

int Queue::show_front()
{
	int top = LLq.at(0);
	return top;
}

int Queue::size()
{
	return LLq.size();
}

bool Queue::search_queue(int cur_car)
{
	//bool found = false;
	int data = 0;

	for (int i = 0; i < LLq.size(); i++)
	{
		data = LLq.at(i);
		if (cur_car == data)
		{
			return true;
		}
	}

	return false;
}
