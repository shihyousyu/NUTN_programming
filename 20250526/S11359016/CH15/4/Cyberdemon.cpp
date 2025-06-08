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

string Cyberdemon::getSpecies(){return "Cyberdemon";}
