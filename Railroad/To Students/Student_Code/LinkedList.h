/*
 * LinkedList.h
 *
 *  Created on: May 15, 2014
 *      Author: aconstan
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "Factory.h"
#include "LinkedListInterface.h"
#include <iostream>

using namespace std;

template <class T>

class LinkedList : public LinkedListInterface <T>
{
private:
	struct Node
	{

		T data;
		Node* next;


		Node (T data_item, Node* next_ptr) :
			data (data_item), next (next_ptr) {}
	};


	Node* head;



public:
	LinkedList<T>()
	{
		head = NULL;

	}
	~LinkedList()
	{
		clear();
	}

	//=========================================================================================

	void insertHead(T value)
	{
		Node* cur = head;

		if (cur == NULL)
        {
            Node* n = new Node (value, NULL);
            head = n;
            return;
        }
		while (cur != NULL)
		{
			if (cur->data == value)
				return;
			cur = cur->next;
		}

		Node* n = new Node (value, head);
		head = n;

	}

	void insertTail(T value)
	{
        Node* cur = head;

        if (cur == NULL)
        {
            Node* n = new Node (value, NULL);
            head = n;
            return;
        }

		while (cur != NULL)
		{
			if (cur->data == value)
				return;

            if (cur->next == NULL)
            {
                Node* n = new Node (value, NULL);
                cur->next = n;
                return;
            }

			cur = cur->next;
		}

	}

	void insertAfter(T value, T insertionNode)
	{
        Node* cur = head;

        while (cur != NULL)
		{
			if (cur->data == value)
			{
				return;
			}
			cur = cur->next;
		}

        cur = head;

        while (cur != NULL)
        {
			if (cur->data == insertionNode)
			{
				Node* n = new Node (value, cur->next);
				cur->next = n;
				return;
			}
			cur = cur->next;
        }

	}

	void remove(T value)
	{
	    Node* cur = head;
	    bool found = false;

	    while (cur != NULL)
	    {
	    	if (cur->data != value)
	    	{
	    		found = false;
	    	}
	    	else
	    	{
	    		found = true;
	    		break;
	    	}
	    	cur = cur->next;
	    }

	    cur = head;
	    if (found == true)
	    {
	    	if (cur->next == NULL)
	    	{
	    		delete cur;
	    		head = NULL;
	    		return;
	    	}
	    	while (cur != NULL)
	    	{
	    		if (cur->data == value)
	    		{
	    			head = cur->next;
	    			delete cur;
	    			return;
	    		}
	    		if (cur->next->data == value)
	    		{
	    			Node* n = cur->next;
	    			cur->next = cur->next->next;
	    			delete n;
	    			return;
	    		}
	    		cur = cur->next;
	    	}
	    }
	    else
	    {
	    	return;
	    }
	}

	//======================================================================================

	void clear()
	{
		while (head != NULL)
			remove(head->data);
	}

	T at(int index)
	{
		Node* cur = head;


		if (cur == NULL)
            return NULL;
		if (index < 0)
			return NULL;


		for (int i = 0; i < index; i++)
        {
			cur = cur->next;
			if (cur == NULL)
			{
				return NULL;
			}

        }
		return cur->data;
	}

	int size()
	{

		int number = 0;
		Node* cur = head;

		if (head == NULL)
			return 0;

        while (cur != NULL)
        {
            cur = cur->next;
            number++;
        }

		return number;
	}

};



#endif /* LINKEDLIST_H_ */
