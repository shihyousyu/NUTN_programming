#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Human.h"
#include "Elf.h"
#include "Cyberdemon.h"
#include "Balrog.h"
using namespace std;

void battleArena(Creature &creature1, Creature &creature2) {
    int round = 1;
    while (creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0) {
        cout << "=== Round " << round++ << " ===\n";

        int damage1 = creature1.getDamage();
        int damage2 = creature2.getDamage();

        creature2.setHitpoints(creature2.getHitpoints() - damage1);
        creature1.setHitpoints(creature1.getHitpoints() - damage2);

        cout << creature1.getSpecies() << " HP: " << creature1.getHitpoints() << "\n";
        cout << creature2.getSpecies() << " HP: " << creature2.getHitpoints() << "\n\n";
    }

    if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() <= 0)
        cout << "Battle ends in a tie!\n";
    else if (creature1.getHitpoints() <= 0)
        cout << creature2.getSpecies() << " wins!\n";
    else
        cout << creature1.getSpecies() << " wins!\n";
}

int main() {
    srand(time(NULL));

    Human h(30, 100);
    Elf e(25, 80);
    Cyberdemon c(35, 90);
    Balrog b(40, 100);

    battleArena(h, c);
    battleArena(e, b);

    return 0;
}
