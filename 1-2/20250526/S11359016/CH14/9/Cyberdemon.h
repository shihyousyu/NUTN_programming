#ifndef CYBERDEMON_H
#define CYBERDEMON_H

#include<iostream>
#include<string>
#include"Demon.h"
using std::string;
using std::cout;

class Cyberdemon : public Demon{
    private:
        string getSpecies();
    public:
        Cyberdemon();
        Cyberdemon(int newStrength, int newHit);
        int getDamage();
};

#endif