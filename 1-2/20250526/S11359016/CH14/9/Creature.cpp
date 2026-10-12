#include<iostream>
#include<string>
#include"Creature.h"
using std::string;
using std::cout;

Creature::Creature(){
    strength = 10;
    hitpoints = 10;
}
Creature::Creature(int newStrength, int newHit){
    strength = newStrength > 0 ? newStrength : 10;
    hitpoints = newHit;
}

int Creature::getDamage(){
    int damage = (rand() % strength) + 1;
    cout << "Creature attacks for " << damage << " points!\n";
    return damage;
}
string Creature::getSpecies(){return "Unknown";}
