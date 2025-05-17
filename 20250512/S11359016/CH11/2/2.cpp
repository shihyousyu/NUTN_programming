#include<iostream>
#include"pfarrayd.h"

void testPFArrayD(){
    using namespace PFAD;
    
    int cap;
    std::cout << "Enter capacity of this super array: ";
    std::cin >> cap;
    PFArrayD temp(cap);

    std::cout << "Enter up to " << cap << " nonnegative numbers.\n";
    std::cout << "Place a negative number at the end.\n";
    double next;
    std::cin >> next;
    while((next >= 0) && (!temp.full())){
        temp.addElement(next);
        std::cin >> next;
    }

    std::cout << "You entered the following " << temp.getNumberUsed() << " numbers:\n";
    for(int i = 0; i < temp.getNumberUsed(); i++) std::cout << temp[i] << " ";
    std::cout << std::endl;
    std::cout << "(plus a sentinel value.)\n";
}

int main(){
    std::cout << "This program tests the PFArrayD class.\n";
    char ans;
    do{
        testPFArrayD();
        std::cout << "Test again? (y/n): ";
        std::cin >> ans;
    }while(ans == 'y' || ans == 'Y');
    return 0;
}