#include "Rplayer.h"

using namespace std;

Rplayer::Rplayer(string name_in, int strength_in, int speed_in)
{
    name = name_in;
    strength = strength_in;
    speed = speed_in;
}
Rplayer::~Rplayer()
{

}

string Rplayer::getName()
{
    return name;
}

int Rplayer::getStrength()
{
    return strength;
}

int Rplayer::getSpeed()
{
    return speed;
}
