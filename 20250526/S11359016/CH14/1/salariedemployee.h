#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "employee.h"
using std::string;

namespace SavitchEmployees{
    class SalariedEmployee : public Employee{
        protected:
            double salary;//weekly
        public:
            SalariedEmployee();
            SalariedEmployee(const string& theName, const string& theSsn, double theWeeklyPay);
            double getSalary() const;
            void setSalary(double newSalary);
            void printCheck();
    };
}

#endif