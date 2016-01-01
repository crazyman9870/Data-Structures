/*
 * Deque.cpp
 *
 *  Created on: May 27, 2014
 *      Author: aconstan
 */

#include "Deque.h"

using namespace std;

Deque::Deque()
{

}

Deque::~Deque()
{

}

//Extra Fxns=============================================================================================

void Deque::insert_right(int cur_car)
{
	LLd.insertTail(cur_car);
}

void Deque::insert_left(int cur_car)
{
	LLd.insertHead(cur_car);
}

int Deque::remove_right()
{
	int right_pos =	LLd.size() - 1;
	int right_data = LLd.at(right_pos);
	LLd.remove(LLd.at(right_pos));
	return right_data;
}

int Deque::remove_left()
{
	int left = LLd.at(0);
	LLd.remove(LLd.at(0));
	return left;
}

int Deque::show_left()
{
	int left = LLd.at(0);
	return left;
}

int Deque::show_right()
{
	int right_pos =	LLd.size() - 1;
	int right_data = LLd.at(right_pos);
	return right_data;
}

int Deque::size()
{
	return LLd.size();
}

bool Deque::search_deque(int cur_car)
{
	//bool found = false;
	int data = 0;

	for (int i = 0; i < LLd.size(); i++)
	{
		data = LLd.at(i);
		if (cur_car == data)
		{
			return true;
		}
	}

	return false;
}
