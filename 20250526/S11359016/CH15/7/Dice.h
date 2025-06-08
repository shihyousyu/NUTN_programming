#ifndef DICE_H
#define DICE_H

#include <cstdlib>
#include <ctime>

class Dice{
    protected:
        int numSides;
    public:
        Dice();
        Dice(int numSides);
        virtual int rollDice() const;
};

#endif
