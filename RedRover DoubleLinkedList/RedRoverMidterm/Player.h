//Anthony Constantino CS 235 Spring 2014 Midterm

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

//#include "DLinkedList.h"
#include <string>
#include <iostream>

using namespace std;

class Player
{
private:

    //DLinkedList<string> DLL;
    string name;
    int strength;
    int speed;

public:
    Player(string name_in, int strength_in, int speed_in);
    virtual~Player();

//Functions=================================================================

string getName();

int getStrength();

int getSpeed();

//string toString();

};


#endif // PLAYER_H_INCLUDED
