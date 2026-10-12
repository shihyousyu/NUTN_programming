#include<iostream>
#include<string>
#include"Creature.h"
#include"Demon.h"
using std::string;
using std::cout;

Demon::Demon(){
    strength = 10;
    hitpoints = 10;
}
Demon::Demon(int newStrength, int newHit){
    strength = newStrength > 0 ? newStrength : 10;
    hitpoints = newHit;
}

int Demon::getDamage(){
    return inherentAbility(Creature::getDamage());
}

int Demon::inherentAbility(int damage){
    if((rand() % 100) < 5){
        damage = damage + 50;
        cout << "Demonic attack inflicts 50 "
        << " additional damage points!\n";
    }
    return damage;
}

string Demon::getSpecies(){return "Demon";}
