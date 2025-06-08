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

int Creature::getDamage(){
    cout << "[ERROR OCCURED]\n";
    return 0;
}
string Creature::getSpecies(){return "Unknown";}