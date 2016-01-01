#ifndef DLINKEDLIST2_H_INCLUDED
#define DLINKEDLIST2_H_INCLUDED

#include <iostream>
#include "Player.h"

using namespace std;

template <class ItemType>

class DLinkedList
{
private:
    struct Node
	{
        int data;
        //string strength;
        //string speed;
        Node* next;
        Node* prev;

        Node(string data_item,// string strength_item, string speed_item,
            Node* next_ptr, Node* prev_ptr) :
            data(data_item),// strength(strength_item), speed(speed_item),
            next(next_ptr), prev(prev_ptr) {}
    };

	Node* head;
	//Player* tail;
	//int count;

public:
	DLinkedList(void)
	{
	    head = NULL;
	    //tail = NULL;
	    //count = 0;
    }
    ~DLinkedList()
	{
		clear();
	}

//=========================================================================================

    void insertHead(Player player)
    {
        Node* cur = head;

        if (cur == NULL)
        {
            Node* n = new Node (player, NULL, NULL);
            head = n;
            return;
        }
        while (cur != NULL)
        {
            if (cur->data == player)
            {
                return;
            }
            cur = cur->next;
        }

        Node* n = new Node (player, head, NULL);
        head->prev = n;
        head = n;




    }

    void insertTail(Player player)
    {
        Node* cur = head;

        if (cur == NULL)
        {
            Node* n = new Node (player, NULL, NULL);
            head = n;
            return;
        }

        while (cur != NULL)
        {
            if (cur->data == player)
            {
               return;
            }

            if (cur->next == NULL)
            {
                Node* n = new Node (player, NULL, cur);
                cur->next = n;
                return;
            }

            cur = cur->next;
        }

    }

    void insertAfter(Player player, Player insertionPlayer)
    {
        Node* cur = head;

        while (cur != NULL)
        {
            if (cur->data == player)
            {
                return;
            }
            cur = cur->next;
        }

        cur = head;

        while (cur != NULL)
        {
            if (cur->data == insertionPlayer)
            {
                Node* n = new Node (player, cur->next, cur);
                cur->next = n;
                if (cur->next->next != NULL)
                {
                    cur = cur->next->next;
                    cur->prev = n;
                }

                return;
            }
            cur = cur->next;
        }

    }

    void remove(Player player)
    {
        Node* cur = head;
        bool found = false;

        while (cur != NULL)
        {
            if (cur->data != player)
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
                if (cur->data == player)
                {
                    head = cur->next;
                    head->prev = NULL;
                    delete cur;
                    return;
                }
                if (cur->next->data == player)
                {
                    Node* n = cur->next;
                    cur = cur->next->next;
                    cur->prev = cur->prev->prev;
                    cur = cur->prev;
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

//=========================================================================================

    void clear()
    {
        while (head != NULL)
        {
            remove(head->data);
        }
    }

    string at(int index)
    {
        Node* cur = head;


        if (cur == NULL)
        {
            return NULL;
        }
        if (index < 0)
        {
            return NULL;
        }

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

//End DLL Begin extra functions==========================================================================

/*
string getName(int index)
{
    Player* cur = head;

    for (int i = 0; i < index; i++)
    {
        cur = cur->next;
        if (cur == NULL)
        {
            return NULL;
        }
    }

    return name;
}

int getStrength(int index)
{
    Player* cur = head;

    for (int i = 0; i < index; i++)
    {
        cur = cur->next;
        if (cur == NULL)
        {
            return NULL;
        }
    }
    return strength;
}

int getSpeed(int index)
{
    Player* cur = head;

    for (int i = 0; i < index; i++)
    {
        cur = cur->next;
        if (cur == NULL)
        {
            return NULL;
        }
    }
    return speed;
}
*/
};

#endif // DLINKEDLIST_H_INCLUDED


#endif // DLINKEDLIST2_H_INCLUDED
