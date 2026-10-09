#include<iostream>
#include<string>
#include"Creature.h"
#include"Demon.h"
using std::string;
using std::cout;

Demon::Demon(){
    strength = 0;
    hitpoints = 0;
}
Demon::Demon(int newStrength, int newHit){
    strength = newStrength;
    hitpoints = newHit;
}

int Demon::getDamage(){
    cout << "[ERROR OCCURED]\n";
    return 0;
}

int Demon::inherentAbility(int damage){
    srand(time(NULL));
    if((rand() % 100) < 5){
        damage = damage + 50;
        cout << "Demonic attack inflicts 50 "
        << " additional damage points!\n";
    }
    return damage;
}

string Demon::getSpecies(){return "Demon";}