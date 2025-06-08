#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <iostream>
#include <string>
#include "salariedemployee.h"
using std::string;

namespace SavitchEmployees{
    class Administrator : public SalariedEmployee{
        private:
            string adminTitle;
            string responsibility;
            string supervisorName;
        public:
            Administrator();
            Administrator(const string& theName, const string& theNumber, double theWeeklyPay, const string& adminTitle, const string& responsibility, const string& supervisorName);
            void setSupervisor(const string& supervisorName);
            void inputAdministratorData();
            void print() const;
            void printCheck();
    };
}

#endif