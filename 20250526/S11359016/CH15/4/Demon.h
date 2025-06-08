#ifndef DEMON_H
#define DEMON_H

#include"Creature.h"

class Demon : public Creature{
public:
    Demon();
    Demon(int newStrength, int newHit);

    virtual int getDamage() override;
    virtual string getSpecies() override;

protected:
    int inherentAbility(int damage);
};

#endif
