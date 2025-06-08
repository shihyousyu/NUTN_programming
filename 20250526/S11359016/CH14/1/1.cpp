#include <iostream>
#include <string>
#include "administrator.h"
using namespace std;

int main(){
    using namespace SavitchEmployees;

    Administrator admin;
    string name, title, responsibility, supervisor;

    cout << "Admin: ";
    cin >> name;
    admin.setName(name);
    admin.inputAdministratorData();
    admin.print();
    return 0;

}