#include<iostream>
#include<string>
#include"Creature.h"
using std::string;
using std::cout;

Creature::Creature(){
    strength = 0;
    hitpoints = 0;
}
Creature::Creature(int newStrength, int newHit){
    strength = newStrength;
    hitpoints = newHit;
}

void Creature::setHitpoints(int newHitpoints) {
    hitpoints = newHitpoints;
    if (hitpoints < 0) hitpoints = 0;
}

int Creature::getDamage(){
    int damage = (rand() % strength) + 1;
    cout << getSpecies() << " attacks for " << damage << " points!\n";
    return damage;
}
string Creature::getSpecies(){return "Unknown";}