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
    strength = newStrength > 0 ? newStrength : 10;
    hitpoints = newHit;
}

int Cyberdemon::getDamage(){
    int damage;
    damage = Demon::getDamage();
    cout << getSpecies() << " attacks for " << damage << " points!\n";

    return damage;
}

string Cyberdemon::getSpecies(){return "Cyberdemon";}
