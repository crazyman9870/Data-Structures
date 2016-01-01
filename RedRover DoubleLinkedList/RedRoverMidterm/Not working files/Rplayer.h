#ifndef RPLAYER_H_INCLUDED
#define RPLAYER_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Rplayer
{
private:
    string name;
    int strength;
    int speed;

public:
    Rplayer(string name_in, int strength_in, int speed_in);
    virtual~Rplayer();

    string getName();

    int getStrength();

    int getSpeed();
};

#endif // RPLAYER_H_INCLUDED
