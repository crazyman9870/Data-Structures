/*
 * IRDeque.cpp
 *
 *  Created on: May 27, 2014
 *      Author: aconstan
 */

#include "IRDeque.h"

using namespace std;

IRDeque::IRDeque()
{

}

IRDeque::~IRDeque()
{

}


void IRDeque::insert_left(int cur_car)
{
	LLIR.insertHead(cur_car);
}

int IRDeque::remove_right()
{
	int right_pos =	LLIR.size() - 1;
	int right_data = LLIR.at(right_pos);
	LLIR.remove(LLIR.at(right_pos));
	return right_data;
}

int IRDeque::remove_left()
{
	int left = LLIR.at(0);
	LLIR.remove(LLIR.at(0));
	return left;
}

int IRDeque::show_left()
{
	int left = LLIR.at(0);
	return left;
}

int IRDeque::show_right()
{
	int right_pos =	LLIR.size() - 1;
	int right_data = LLIR.at(right_pos);
	return right_data;
}

int IRDeque::size()
{
	return LLIR.size();
}

bool IRDeque::search_IRdeque(int cur_car)
{
	//bool found = false;
	int data = 0;

	for (int i = 0; i < LLIR.size(); i++)
	{
		data = LLIR.at(i);
		if (cur_car == data)
		{
			return true;
		}
	}

	return false;
}

