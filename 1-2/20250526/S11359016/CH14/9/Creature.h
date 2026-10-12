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
        int getStrength() const { return strength; }
        void setStrength(int value) { if(value > 0) strength = value; }
        int getHitpoints() const { return hitpoints; }
        void setHitpoints(int value) { hitpoints = value; }
};

#endif
