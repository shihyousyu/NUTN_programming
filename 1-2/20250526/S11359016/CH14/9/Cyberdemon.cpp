#include<iostream>
#include<string>
#include"Demon.h"
#include"Cyberdemon.h"
using std::string;
using std::cout;

Cyberdemon::Cyberdemon(){
    strength = 10;
    hitpoints = 10;
}

Cyberdemon::Cyberdemon(int newStrength, int newHit){
    strength = newStrength;
    hitpoints = newHit;
}

int Cyberdemon::getDamage(){
    int damage;
    srand(time(NULL));
    damage = (rand() % strength) + 1;
    cout << getSpecies() << " attacks for " << damage << " points!\n";

    damage = inherentAbility(damage);
    return damage;
}

string Cyberdemon::getSpecies(){return "Cyberdemon";}