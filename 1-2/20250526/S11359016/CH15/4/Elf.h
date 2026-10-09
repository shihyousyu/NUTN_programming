#ifndef ELF_H
#define ELF_H

#include<iostream>
#include<string>
#include"Creature.h"
using std::string;
using std::cout;

class Elf : public Creature{
    public:
        Elf();
        Elf(int newStrength, int newHit);

        virtual int getDamage() override;
        virtual string getSpecies() override;
};

#endif
