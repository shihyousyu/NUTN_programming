#include <iostream>
#include "Dice.h"
#include "LoadedDice.h"

using std::cout;
using std::endl;

int rollTwoDice(const Dice& die1, const Dice& die2) {
    return die1.rollDice() + die2.rollDice();
}

int main() {
    srand(time(NULL));
    Dice d1(6);
    Dice d2(10);

    cout << "Testing normal dice:\n";
    for(int i = 0; i < 10; i++) cout << rollTwoDice(d1, d2) << "\n";

    LoadedDice ld1(6);
    LoadedDice ld2(10);

    cout << "\nTesting loaded dice:\n";
    for(int i = 0; i < 10; i++) cout << rollTwoDice(ld1, ld2) << "\n";

    return 0;
}
