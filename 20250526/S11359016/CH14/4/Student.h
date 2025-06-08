#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include<string>
#include"UniversityStaff.h"
using std::string;
using std::istream;
using std::ostream;
using std::cout;

class Student{
    protected:
        string UniversityName;
        int RegistrationNumber;
        UniversityStaff proctor;
    public:
        Student();
        Student(string u, int r, UniversityStaff p);
        Student(const Student& t);

        void setUniversityName(string u);
        void setRegistrationNumber(int r);
        void setUniversityStaff(const UniversityStaff& p);
        
        string getUniversityName() const;
        int getRegistrationNumber() const;
        UniversityStaff getUniversityStaff() const;
        
        Student& operator=(const Student& rtSide);
        friend istream& operator>>(istream& inStream, Student& studentObject);
        friend ostream& operator<<(ostream& outStream, const Student& studentObject);
};

#endif