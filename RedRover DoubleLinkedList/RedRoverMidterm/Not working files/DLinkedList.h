#ifndef DLINKEDLIST_H_INCLUDED
#define DLINKEDLIST_H_INCLUDED

#include <iostream>

using namespace std;

template <class ItemType>

class DLinkedList
{
private:
	struct Player
	{
		ItemType name;
		ItemType strength;
		ItemType speed;
		Player* next;
		Player* prev;

		Player(ItemType name_item, ItemType strength_item, ItemType speed_item,
            Player* next_ptr, Player* prev_ptr) :
		    name(name_item), strength(strength_item), speed(speed_item),
		    next(next_ptr), prev(prev_ptr) {}
	};


	Player* head;
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

    void insertHead(ItemType player, ItemType power, ItemType spd)
    {
        Player* cur = head;

        if (cur == NULL)
        {
            Player* n = new Player (player, power, spd, NULL, NULL);
            head = n;
            return;
        }
        while (cur != NULL)
        {
            if (cur->name == player)
            {
                return;
            }
            cur = cur->next;
        }

        Player* n = new Player (player, power, spd, head, NULL);
        head = n;
        cur = cur->prev;
        cur->prev = n;


    }

    void insertTail(ItemType player, ItemType power, ItemType spd)
    {
        Player* cur = head;

        if (cur == NULL)
        {
            Player* n = new Player (player, power, spd, NULL, NULL);
            head = n;
            return;
        }

        while (cur != NULL)
        {
            if (cur->name == player)
            {
               return;
            }

            if (cur->next == NULL)
            {
                Player* n = new Player (player, power, spd, NULL, head);
                cur->next = n;
                return;
            }

            cur = cur->next;
        }

    }

    void insertAfter(ItemType player, ItemType power, ItemType spd, ItemType insertionPlayer)
    {
        Player* cur = head;

        while (cur != NULL)
        {
            if (cur->name == player)
            {
                return;
            }
            cur = cur->next;
        }

        cur = head;

        while (cur != NULL)
        {
            if (cur->name == insertionPlayer)
            {
                Player* n = new Player (player, power, spd, cur->next, cur);
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

    void remove(ItemType player)
    {
        Player* cur = head;
        bool found = false;

        while (cur != NULL)
        {
            if (cur->name != player)
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
                if (cur->name == player)
                {
                    head = cur->next;
                    head->prev = NULL;
                    delete cur;
                    return;
                }
                if (cur->next->name == player)
                {
                    Player* n = cur->next;
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
            remove(head->name); //head->name
        }
    }

    ItemType at(int index)
    {
        Player* cur = head;


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
        return cur->name;
    }

    int size()
    {

        int number = 0;
        Player* cur = head;

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

#endif // DLINKEDLIST_H_INCLUDED
