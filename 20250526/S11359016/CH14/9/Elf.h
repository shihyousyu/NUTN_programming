#ifndef ELF_H
#define ELF_H

#include<iostream>
#include<string>
#include"Creature.h"
using std::string;
using std::cout;

class Elf : public Creature{
    private:
        string getSpecies();
    public:
        Elf();
        Elf(int newStrength, int newHit);
        int getDamage();
};

#endif