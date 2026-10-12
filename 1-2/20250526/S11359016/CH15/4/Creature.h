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
        virtual string getSpecies();
        
        int getStrength() const {return strength;}
        void setStrength(int value) {strength = value;}
        
        void setHitpoints(int newHitpoints);
        int getHitpoints() const{return hitpoints;}
};

#endif
