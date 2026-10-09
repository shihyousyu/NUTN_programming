#include <iostream>
#include <cstdlib>
#include "pfarrayd.h"

PFAD::PFArrayD::PFArrayD() : capacity(50), used(0){a = new double[capacity];}
PFAD::PFArrayD::PFArrayD(int size) : capacity(size), used(0){a = new double[capacity];}
PFAD::PFArrayD::PFArrayD(const PFArrayD& pfaObject) : capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed()){
    a = new double[capacity];
    for(int i = 0; i < used; i++) a[i] = pfaObject.a[i];
}
PFAD::PFArrayD::~PFArrayD(){delete[] a;}

void PFAD::PFArrayD::addElement(double element){
    if(used >= capacity){
        std::cout << "Attempt to exceed capacity.\n";
        std::exit(0);
    }
    a[used++] = element;
}

bool PFAD::PFArrayD::full() const{return (used == capacity);}

int PFAD::PFArrayD::getCapacity() const{return capacity;}
int PFAD::PFArrayD::getNumberUsed() const{return used;}

void PFAD::PFArrayD::emptyArray(){used = 0;}

double& PFAD::PFArrayD::operator[](int index){
    if(index >= used){
        std::cout << "Illegal index.\n";
        std::exit(0);
    }
    return a[index];
}
PFAD::PFArrayD& PFAD::PFArrayD::operator =(const PFArrayD& rightSide){
    if(this != &rightSide){
        if(capacity != rightSide.capacity){
            delete[] a;
            a = new double[rightSide.capacity];
        }
        capacity = rightSide.capacity;
        used = rightSide.used;
        for(int i = 0; i < used; i++) a[i] = rightSide.a[i];
    }
    return *this;
}