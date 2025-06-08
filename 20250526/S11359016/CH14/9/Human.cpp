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
    int damage;
    srand(time(NULL));
    damage = (rand() % strength) + 1;
    cout << getSpecies() << " attacks for " << damage << " points!\n";
    return damage;
}

string Human::getSpecies(){return "Human";}