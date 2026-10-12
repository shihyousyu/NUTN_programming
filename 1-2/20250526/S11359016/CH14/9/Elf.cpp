#include<iostream>
#include<string>
#include"Creature.h"
#include"Elf.h"
using std::string;
using std::cout;

Elf::Elf(){
    strength = 10;
    hitpoints = 10;
}
Elf::Elf(int newStrength, int newHit){
    strength = newStrength > 0 ? newStrength : 10;
    hitpoints = newHit;
}

int Elf::getDamage(){
    int damage;
    damage = Creature::getDamage();
    cout << getSpecies( ) << " attacks for " << damage << " points!\n";

    if((rand() % 10) == 0){
        cout << "Magical attack inflicts " << damage << " additional damage points!\n";
        damage = damage * 2;
    }
    return damage;
}

string Elf::getSpecies(){return "Elf";}
