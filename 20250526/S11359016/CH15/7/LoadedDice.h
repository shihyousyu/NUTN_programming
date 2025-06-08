#ifndef LOADEDDICE_H
#define LOADEDDICE_H

#include "Dice.h"

class LoadedDice : public Dice{
    public:
        LoadedDice();
        LoadedDice(int numSides);
        int rollDice() const override;
};

#endif
