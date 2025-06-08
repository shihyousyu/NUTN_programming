#ifndef BALROG_H
#define BALROG_H

#include<iostream>
#include<string>
#include"Demon.h"
using std::string;
using std::cout;

class Balrog : public Demon{
    private:
        string getSpecies();
    public:
        Balrog();
        Balrog(int newStrength, int newHit);
        int getDamage();
};

#endif