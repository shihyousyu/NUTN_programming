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

    public:
        Creature();
        Creature(int newStrength, int newHit);

        virtual int getDamage();
        int getStrength() const { return strength; }
        void setStrength(int value) { if(value > 0) strength = value; }
        virtual string getSpecies();

        void setHitpoints(int newHitpoints);
        int getHitpoints() const{return hitpoints;}
};

#endif
