#include<iostream>
#include<string>
#include"Creature.h"
#include"Human.h"
using std::string;
using std::cout;

Human::Human(){
    strength = 10;
    hitpoints = 10;
}

Human::Human(int newStrength, int newHit){
    strength = newStrength;
    hitpoints = newHit;
}

int Human::getDamage(){
    int damage = Creature::getDamage();
    return damage;
}

string Human::getSpecies(){return "Human";}