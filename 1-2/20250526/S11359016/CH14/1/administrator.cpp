#include <iostream>
#include <string>
#include "salariedemployee.h"
#include "administrator.h"
using std::string;
using std::cin;
using std::cout;

namespace SavitchEmployees{
    Administrator::Administrator(){
        adminTitle = "No title yet";
        responsibility = "No responsibility yet";
        supervisorName = "No supervisor yet";
    }

    Administrator::Administrator(const string& theName, const string& theNumber, double theAnnualSalary, const string& adminTitle, const string& responsibility, const string& supervisorName) :
        SalariedEmployee(theName, theNumber, theAnnualSalary), adminTitle(adminTitle), responsibility(responsibility), supervisorName(supervisorName){}

    void Administrator::setSupervisor(const string& newSupervisorName){supervisorName = newSupervisorName;}

    void Administrator::inputAdministratorData(){
        cout << "Annual salary: ";
        cin >> salary;
        cout << "Administrator's title: ";
        getline(cin >> std::ws, adminTitle);
        cout << "Responsibility: ";
        getline(cin >> std::ws, responsibility);
        cout << "Supervisor name: ";
        getline(cin >> std::ws, supervisorName);
    }

    void Administrator::print() const{
        cout << "\nDATA: \n";
        cout << "\tName: " << getName() << "\n";
        cout << "\tAnnual salary: " << salary << "\n";
        cout << "\tTitle: " << adminTitle << "\n";
        cout << "\tResponsibility: " << responsibility << "\n";
        cout << "\tSupervisor name: " << supervisorName << "\n";
    }

    void Administrator::printCheck(){
        setNetPay(salary);
        cout << "\n________________________________________________\n";
        cout << "Pay to the order of " << getName( ) << "\n";
        cout << "The sum of " << getNetPay( ) << " Dollars\n";
        cout << "_________________________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "Employee Number: " << getSsn( ) << "\n";
        cout << "Salaried Employee (Administrator). Annual Salary: " << getNetPay() << "\n";
        cout << "_________________________________________________\n";
    }

}
