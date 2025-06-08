#ifndef HUMAN_H
#define HUMAN_H

#include<iostream>
#include<string>
#include"Creature.h"
using std::string;
using std::cout;

class Human : public Creature{
    private:
        string getSpecies();
    public:
        Human();
        Human(int newStrength, int newHit);
        int getDamage();
};

#endif