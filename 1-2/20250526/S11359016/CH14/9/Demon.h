#ifndef DEMON_H
#define DEMON_H

#include<iostream>
#include<string>
#include"Creature.h"
using std::string;
using std::cout;

class Demon : public Creature{
    protected:
        int inherentAbility(int damage);
        string getSpecies();
    public:
        Demon();
        Demon(int newStrength, int newHit);
        int getDamage();
};

#endif