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
    strength = newStrength;
    hitpoints = newHit;
}

int Demon::getDamage(){
    int damage = Creature::getDamage();

    damage = inherentAbility(damage);

    return damage;
}

int Demon::inherentAbility(int damage){
    if((rand() % 100) < 5){
        damage += 50;
        cout << "Demonic attack inflicts 50 additional damage points!\n";
    }
    return damage;
}

string Demon::getSpecies(){return "Demon";}
