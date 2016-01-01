/*
 * Stack.cpp
 *
 *  Created on: May 27, 2014
 *      Author: aconstan
 */

#include "Stack.h"

using namespace std;


Stack::Stack()
{

}

Stack::~Stack()
{

}

//Extra Fxns=============================================================================================

/*
bool Stack::search_s(stack<int> pile, int car)
{
    bool found = false;
    int check = 0;
    stack<int> box;

    while (pile.empty() != true)
    {
        box.push(pile.top());
        pile.pop();
    }

    while (box.empty() != true)
    {
        check = box.top();
        if (check == car)
        {
            found = true;
        }
        pile.push(box.top());
        box.pop();
    }

    if (found == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
*/

void Stack::add_car(int cur_car)
{
	LLs.insertHead(cur_car);
}

int Stack::remove_car()
{
	int top = LLs.at(0);
	LLs.remove(LLs.at(0));
	return top;
}

int Stack::show_top()
{
	int top = LLs.at(0);
	return top;
}

int Stack::size()
{
	return LLs.size();
}

bool Stack::search_stack(int cur_car)
{
	//bool found = false;
	int data = 0;

	for (int i = 0; i < LLs.size(); i++)
	{
		data = LLs.at(i);
		if (cur_car == data)
		{
			return true;
		}
	}

	return false;
}

