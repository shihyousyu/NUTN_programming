#include<iostream>
#include<string>
#include<ctime>
#include"Human.h"
#include"Cyberdemon.h"
#include"Balrog.h"
#include"Elf.h"
using namespace std;

int main(){
    int i;
    Human human;
    Cyberdemon cyberdemon;
    Balrog balrog;
    Elf elf;

    for(i = 0; i < 5; i++) human.getDamage();
    cout << "\n";
    for(i = 0; i < 5; i++) elf.getDamage();
    cout << "\n";
    for(i = 0; i < 5; i++) cyberdemon.getDamage();
    cout << "\n";
    for(i = 0; i < 5; i++) balrog.getDamage();
    return 0;
}