#include <iostream>
#include <cstdlib>
#include "pfarrayd.h"

namespace PFAD{
    PFArrayD::PFArrayD() : capacity(50), used(0){a = new double[capacity];}
    PFArrayD::PFArrayD(int size) : capacity(size), used(0){a = new double[capacity];}
    PFArrayD::PFArrayD(const PFArrayD& pfaObject) : capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed()){
        a = new double[capacity];
        for(int i = 0; i < used; i++) a[i] = pfaObject.a[i];
    }
    PFArrayD::~PFArrayD(){delete[] a;}

    void PFArrayD::addElement(double element){
        if(used >= capacity){
            std::cout << "Attempt to exceed capacity.\n";
            std::exit(0);
        }
        a[used++] = element;
    }

    bool PFArrayD::full() const{return (used == capacity);}

    int PFArrayD::getCapacity() const{return capacity;}
    int PFArrayD::getNumberUsed() const{return used;}

    void PFArrayD::emptyArray(){used = 0;}

    double& PFArrayD::operator[](int index){
        if(index >= used){
            std::cout << "Illegal index.\n";
            std::exit(0);
        }
        return a[index];
    }
    PFArrayD& PFArrayD::operator =(const PFArrayD& rightSide){
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
}
