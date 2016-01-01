#ifndef STATION_H_INCLUDED
#define STATION_H_INCLUDED

#include "StationInterface.h"
#include "StationInterfaceExtra.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "IRDeque.h"
#include "ORDeque.h"

#include <iostream>
#include <string>


using namespace std;

class Station : public StationInterfaceExtra
{

private:

	int cur_car;
	Stack box;
	Queue line;
	Deque dline;
	IRDeque IR;
	ORDeque OR;

public:
    Station();

	virtual~Station();

//Extra Functions ==================================================================================


//Part 1 ===========================================================================================

bool addToStation(int car);

int showCurrentCar();

bool removeFromStation();

//Part 2 ===========================================================================================

bool addToStack();

bool removeFromStack();

int showTopOfStack();

int showSizeOfStack();

//Part 3 ===========================================================================================

bool addToQueue();

bool removeFromQueue();

int showTopOfQueue();

int showSizeOfQueue();

//Part 4 ===========================================================================================

bool addToDequeLeft();

bool addToDequeRight();

bool removeFromDequeLeft();

bool removeFromDequeRight();

int showTopOfDequeLeft();

int showTopOfDequeRight();

int showSizeOfDeque();

//Extra IR==========================================================================================

bool addToIRDequeLeft();

bool removeFromIRDequeLeft();

bool removeFromIRDequeRight();

int showTopOfIRDequeLeft();

int showTopOfIRDequeRight();

int showSizeOfIRDeque();

//Extra OR==========================================================================================


bool addToORDequeLeft();

bool addToORDequeRight();

bool removeFromORDequeLeft();

int showTopOfORDequeLeft();

int showSizeOfORDeque();

};

#endif // STATION_H_INCLUDED
