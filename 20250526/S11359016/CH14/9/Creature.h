#ifndef CREATURE_H
#define CREATURE_H

#include<iostream>
#include<string>
using std::string;
using std::cout;

class Creature{
    protected:
        int strength;
        int hitpoints;
        string getSpecies();
    public:
        Creature();
        Creature(int newStrengh, int newHit);
        int getDamage();
};

#endif