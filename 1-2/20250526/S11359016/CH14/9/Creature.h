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
        
        int getStrength() const {return strength;}
        void setStrength(int value) {strength = value;}
        
        int getHitpoints() const {return hitpoints;}
        void setHitpoints(int value) {hitpoints = value;}
        
        string getSpecies();
    public:
        Creature();
        Creature(int newStrengh, int newHit);
        int getDamage();
};

#endif