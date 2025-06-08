#include <iostream>
#include <string>
#include "salariedemployee.h"
#include "administrator.h"
using std::string;
using std::cin;
using std::cout;
using std::endl;

namespace SavitchEmployees{
    Administrator::Administrator(){
        SalariedEmployee();
        adminTitle = "No title yet";
        responsibility = "No responsibility yet";
        supervisorName = "No supervisor yet";
    }

    Administrator::Administrator(const string& theName, const string& theNumber, double theWeeklyPay, const string& adminTitle, const string& responsibility, const string& supervisorName) : 
        SalariedEmployee(theName, theNumber, theWeeklyPay), adminTitle(adminTitle), responsibility(responsibility), supervisorName(supervisorName){}

    void Administrator::setSupervisor(const string& newSupervisorName){supervisorName = newSupervisorName;}

    void Administrator::inputAdministratorData(){
        cout << "Administrator's title: ";
        cin >> adminTitle;
        cout << "Responsibility: ";
        cin >> responsibility;
        cout << "Supervisor name: ";
        cin >> supervisorName;
    }

    void Administrator::print() const{
        cout << "\nDATA: " << endl;
        cout << "\tName: " << getName() << endl;
        cout << "\tTitle: " << adminTitle << endl;
        cout << "\tResponsibility: " << responsibility << endl;
        cout << "\tSupervisor name: " << supervisorName << endl;
    }

    void Administrator::printCheck(){
        setNetPay(salary);
        cout << "\n________________________________________________\n";
        cout << "Pay to the order of " << getName( ) << endl;
        cout << "The sum of " << getNetPay( ) << " Dollars\n";
        cout << "_________________________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "Employee Number: " << getSsn( ) << endl;
        cout << "Salaried Employee (Administrator). Regular Pay: " << salary << endl;
        cout << "_________________________________________________\n";
    }

}