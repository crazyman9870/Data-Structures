/*
 * Station.cpp
 *
 *  Created on: May 27, 2014
 *      Author: aconstan
 */

#include "Station.h"

using namespace std;

Station::Station()
{
	cur_car = -1;
}

Station::~Station()
{

}

//Part 1 ===========================================================================================


/**
 * Let another car arrive at the station and become the current car.
 * Do not allow a new car to arrive if any of the following conditions apply:
 * 1.	There is already a current car
 * 2.	The new car's ID already exists in any structure DONE
 * 3.	The new car's ID is negative DONE
 *
 * @param car the ID of the car arriving at the station
 * @return true if the car successfully arrived; false otherwise
 */
bool Station::addToStation(int car)
{
    if (car < 0)
    {
        return false;
    }
    if (cur_car != -1)
    {
    	return false;
    }

    bool founds = false;
    bool foundq = false;
    bool foundd = false;
    bool foundir = false;
    bool foundor = false;

    founds = box.search_stack(car);
    foundq = line.search_queue(car);
    foundd = dline.search_deque(car);
    foundir = IR.search_IRdeque(car);
    foundor = OR.search_ORdeque(car);

    if (founds == true || foundq == true || foundd == true || foundir == true || foundor == true)
    {
    	return false;
    }

    cur_car = car;
    return true;
}

/**
 * Returns the ID of the current car.
 * Return -1 if there is no current car.
 *
 * @return the ID of the current car; -1 if there is no current car
 */
int Station::showCurrentCar()
{
	if (cur_car != -1)
	{
		return cur_car;
	}
	return -1;
}

/**
 * Removes the current car from the station.
 * Does nothing if there is no current car.
 *
 * @return true if the current car successfully left; false otherwise
 */
bool Station::removeFromStation()
{
	if (cur_car != -1)
	{
		cur_car = -1;
		return true;
	}
	return false;

}




//Part 2=================================================================================================

/**
 * Adds the current car to the stack.  After this operation, there should be no current car. DONE
 * Does nothing if there is no current car or if the stack is already full. DONE
 *
 * @return true if the car is successfully added to the stack; false otherwise DONE
 */
bool Station::addToStack()
{
	if (box.size() > 5)
	{
		return false;
	}
	if (cur_car != -1 )
	{
	box.add_car(cur_car);
	cur_car = -1;
	return true;
	}
	return false;
}

/**
 * Removes the first car in the stack and makes it the current car. DONE
 * Does nothing if there is already a current car or if the stack already empty.
 *
 * @return true if the car is successfully removed from the stack; false otherwise
 */
bool Station::removeFromStack()
{
	if (box.size() < 1)
	{
		return false;
	}
	if (cur_car != -1)
	{
		return false;
	}
	cur_car = box.remove_car();
	return true;

}

/**
 * Returns the ID of the first car in the stack.
 *
 * @return the ID of the first car in the stack; -1 if the stack is empty
 */
int Station::showTopOfStack()
{
	if (box.size() == 0)
	{
		return -1;
	}
	return box.show_top();
}

/**
 * Returns the number of cars in the stack.
 *
 * @return the number of cars in the stack
 */
int Station::showSizeOfStack()
{
	return box.size();
}

//Part 3=================================================================================================

/**
 * Adds the current car to the queue.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the queue is already full.
 *
 * @return true if the car is successfully added to the queue; false otherwise
 */
bool Station::addToQueue()
{
	if (line.size() > 5)
	{
		return false;
	}
	if (cur_car != -1)
	{
		line.add_car(cur_car);
		cur_car = -1;
		return true;
	}
	return false;
}

/**
 * Removes the first car in the queue and makes it the current car.
 * Does nothing if there is already a current car or if the queue already empty.
 *
 * @return true if the car is successfully removed from the queue; false otherwise
 */
bool Station::removeFromQueue()
{
	if (line.size() < 1)
	{
		return false;
	}
	if (cur_car != -1)
	{
		return false;
	}
	cur_car = line.remove_car();
	return true;
}

/**
 * Returns the ID of the first car in the queue.
 *
 * @return the ID of the first car in the queue; -1 if the queue is empty
 */
int Station::showTopOfQueue()
{
	if (line.size() == 0)
		{
			return -1;
		}
	return line.show_front();
}

/**
 * Returns the number of cars in the queue.
 *
 * @return the number of cars in the queue
 */
int Station::showSizeOfQueue()
{
	return line.size();
}

//Part 4=================================================================================================

/**
 * Adds the current car to the deque on the left side.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the deque is already full.
 *
 * @return true if the car is successfully added to the deque; false otherwise
 */
bool Station::addToDequeLeft()
{
	if (dline.size() > 5)
	{
		return false;
	}
	if (cur_car != -1)
	{
		dline.insert_left(cur_car);
		cur_car = -1;
		return true;
	}
	return false;
}

/**
 * Adds the current car to the deque on the right side.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the deque is already full.
 *
 * @return true if the car is successfully added to the deque; false otherwise
 */
bool Station::addToDequeRight()
{
	if (dline.size() > 5)
	{
		return false;
	}
	if (cur_car != -1)
	{
		dline.insert_right(cur_car);
		cur_car = -1;
		return true;
	}
	return false;
}

/**
 * Removes the leftmost car in the deque and makes it the current car.
 * Does nothing if there is already a current car or if the deque already empty.
 *
 * @return true if the car is successfully removed from the deque; false otherwise
 */
bool Station::removeFromDequeLeft()
{
	if (dline.size() < 1)
	{
		return false;
	}
	if (cur_car != -1)
	{
		return false;
	}
	cur_car = dline.remove_left();
	return true;

}

/**
 * Removes the rightmost car in the deque and makes it the current car.
 * Does nothing if there is already a current car or if the deque already empty.
 *
 * @return true if the car is successfully removed from the deque; false otherwise
 */
bool Station::removeFromDequeRight()
{
	if (dline.size() < 1)
	{
		return false;
	}
	if (cur_car != -1)
	{
		return false;
	}
	cur_car = dline.remove_right();
	return true;

}

/**
 * Returns the ID of the leftmost car in the deque.
 *
 * @return the ID of the leftmost car in the deque; -1 if the deque is empty
 */
int Station::showTopOfDequeLeft()
{
	if (dline.size() == 0)
		{
			return -1;
		}
	return dline.show_left();
}

/**
 * Returns the ID of the rightmost car in the deque.
 *
 * @return the ID of the rightmost car in the deque; -1 if the deque is empty
 */
int Station::showTopOfDequeRight()
{
	if (dline.size() == 0)
		{
			return -1;
		}
	return dline.show_right();
}

/**
 * Returns the number of cars in the deque.
 *
 * @return the number of cars in the deque
 */
int Station::showSizeOfDeque()
{
	return dline.size();
}

//Extra IR===================================================================================================

//Input-Restricted Deque----------------------------------------------
/**
 * Adds the current car to the IRDeque on the left side.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the IRDeque is already full.
 *
 * @return true if the car is successfully added to the IRDeque; false otherwise
 */
bool Station::addToIRDequeLeft()
{
	if (IR.size() > 5)
		{
			return false;
		}
		if (cur_car != -1)
		{
			IR.insert_left(cur_car);
			cur_car = -1;
			return true;
		}
		return false;
}

/**
 * Removes the leftmost car in the IRDeque and makes it the current car.
 * Does nothing if there is already a current car or if the IRDeque already empty.
 *
 * @return true if the car is successfully removed from the IRDeque; false otherwise
 */
bool Station::removeFromIRDequeLeft()
{
	if (IR.size() < 1)
		{
			return false;
		}
		if (cur_car != -1)
		{
			return false;
		}
		cur_car = IR.remove_left();
		return true;
}

/**
 * Removes the rightmost car in the IRDeque and makes it the current car.
 * Does nothing if there is already a current car or if the IRDeque already empty.
 *
 * @return true if the car is successfully removed from the IRDeque; false otherwise
 */
bool Station::removeFromIRDequeRight()
{
	if (IR.size() < 1)
	{
		return false;
	}
	if (cur_car != -1)
	{
		return false;
	}
	cur_car = IR.remove_right();
	return true;
}

/**
 * Returns the ID of the leftmost car in the IRDeque.
 *
 * @return the ID of the leftmost car in the IRDeque; -1 if the IRDeque is empty
 */
int Station::showTopOfIRDequeLeft()
{
	if (IR.size() == 0)
	{
		return -1;
	}
	return IR.show_left();
}

/**
 * Returns the ID of the rightmost car in the IRDeque.
 *
 * @return the ID of the rightmost car in the IRDeque; -1 if the IRDeque is empty
 */
int Station::showTopOfIRDequeRight()
{
	if (IR.size() == 0)
	{
		return -1;
	}
	return IR.show_right();

}

/**
 * Returns the number of cars in the IRDeque.
 *
 * @return the number of cars in the IRDeque
 */
int Station::showSizeOfIRDeque()
{
	return IR.size();
}

//Extra OR==========================================================================================

//Output-Restricted Deque---------------------------------------------
/**
 * Adds the current car to the ORDeque on the left side.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the ORDeque is already full.
 *
 * @return true if the car is successfully added to the ORDeque; false otherwise
 */
bool Station::addToORDequeLeft()
{
	if (OR.size() > 5)
	{
		return false;
	}
	if (cur_car != -1)
	{
		OR.insert_left(cur_car);
		cur_car = -1;
		return true;
	}
	return false;
}

/**
 * Adds the current car to the ORDeque on the right side.  After this operation, there should be no current car.
 * Does nothing if there is no current car or if the ORDeque is already full.
 *
 * @return true if the car is successfully added to the ORDeque; false otherwise
 */
bool Station::addToORDequeRight()
{
	if (OR.size() > 5)
	{
		return false;
	}
	if (cur_car != -1)
	{
		OR.insert_right(cur_car);
		cur_car = -1;
		return true;
	}
	return false;
}

/**
 * Removes the leftmost car in the ORDeque and makes it the current car.
 * Does nothing if there is already a current car or if the ORDeque already empty.
 *
 * @return true if the car is successfully removed from the ORDeque; false otherwise
 */
bool Station::removeFromORDequeLeft()
{
	if (OR.size() < 1)
	{
		return false;
	}
	if (cur_car != -1)
	{
		return false;
	}
	cur_car = OR.remove_left();
	return true;
}

/**
 * Returns the ID of the leftmost car in the ORDeque.
 *
 * @return the ID of the leftmost car in the ORDeque; -1 if the ORDeque is empty
 */
int Station::showTopOfORDequeLeft()
{
	if (OR.size() == 0)
	{
		return -1;
	}
	return OR.show_left();
}

/**
 * Returns the number of cars in the ORDeque.
 *
 * @return the number of cars in the ORDeque
 */
int Station::showSizeOfORDeque()
{
	return OR.size();
}
