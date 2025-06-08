#include<iostream>
#include<string>
#include<Demon.h>
#include"Balrog.h"
using std::string;
using std::cout;

Balrog::Balrog(){
    strength = 10;
    hitpoints = 10;
}

Balrog::Balrog(int newStrength, int newHit){
    strength = newStrength;
    hitpoints = newHit;
}

int Balrog::getDamage(){
    int damage = Demon::getDamage();

    int damage2 = (rand() % strength) + 1;
    cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!\n";
    damage += damage2;

    return damage;
}

string Balrog::getSpecies(){return "Balrog";}
