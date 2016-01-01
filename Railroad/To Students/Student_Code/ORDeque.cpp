/*
 * ORDeque.cpp
 *
 *  Created on: May 27, 2014
 *      Author: aconstan
 */

#include "ORDeque.h"

using namespace std;

ORDeque::ORDeque()
{

}

ORDeque::~ORDeque()
{

}

void ORDeque::insert_right(int cur_car)
{
	LLOR.insertTail(cur_car);
}

void ORDeque::insert_left(int cur_car)
{
	LLOR.insertHead(cur_car);
}

int ORDeque::remove_left()
{
	int left = LLOR.at(0);
	LLOR.remove(LLOR.at(0));
	return left;
}

int ORDeque::show_left()
{
	int left = LLOR.at(0);
	return left;
}

int ORDeque::size()
{
	return LLOR.size();
}

bool ORDeque::search_ORdeque(int cur_car)
{
	//bool found = false;
	int data = 0;

	for (int i = 0; i < LLOR.size(); i++)
	{
		data = LLOR.at(i);
		if (cur_car == data)
		{
			return true;
		}
	}

	return false;
}
