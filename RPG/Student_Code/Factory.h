/*
 *	WARNING: It is expressly forbidden to modify any part of this document, including its name
 */
#pragma once
#include "ArenaInterface.h"
using namespace std;

//=======================================================================================
/*
 *	createArena()
 *
 *	Creates and returns an object whose class extends ArenaInterface.
 *	This should be an object of a class you have created.
 *
 *	Example: If you made a class called "Arena", you might say, "return new Arena();".
 */
class Factory
{
	public:
		static ArenaInterface* createArena();
};
//=======================================================================================
