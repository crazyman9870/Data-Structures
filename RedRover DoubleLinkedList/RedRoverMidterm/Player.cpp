//Anthony Constantino CS 235 Spring 2014 Midterm

#include "Player.h"

using namespace std;

Player::Player(string name_in, int strength_in, int speed_in)
{
    name = name_in;
    strength = strength_in;
    speed = speed_in;
}
Player::~Player()
{

}

//Functions=============================================================

string Player::getName()
{
    return name;
}

int Player::getStrength()
{
    return strength;
}

int Player::getSpeed()
{
    return speed;
}

/*string Player::toString()
{
	stringstream ss;
	ss << "Name: " << name << endl;
	ss << "Strength: " << strength << endl;
	ss << "Speed: $" << speed << endl;
	return ss.str();
}*/
