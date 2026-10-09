#include<iostream>
#include<string>
#include"UniversityStaff.h"
#include"Student.h"
using std::string;
using std::istream;
using std::ostream;
using std::cout;

Student::Student() : UniversityName("no name yet"), RegistrationNumber(0), proctor(UniversityStaff()){}
Student::Student(string u, int r, UniversityStaff p) : UniversityName(u), RegistrationNumber(r), proctor(p){}
Student::Student(const Student& theObject) : UniversityName(theObject.UniversityName), RegistrationNumber(theObject.RegistrationNumber), proctor(theObject.proctor){}

void Student::setUniversityName(string u){UniversityName = u;}
void Student::setRegistrationNumber(int r){RegistrationNumber = r;}
void Student::setUniversityStaff(const UniversityStaff& p){proctor = p;}

string Student::getUniversityName() const{return UniversityName;}

int Student::getRegistrationNumber() const{return RegistrationNumber;}

UniversityStaff Student::getUniversityStaff() const{return proctor;}

Student& Student::operator=(const Student& rtSide){
    UniversityName = rtSide.UniversityName;
    RegistrationNumber = rtSide.RegistrationNumber;
    proctor = rtSide.proctor;
}
istream& operator>>(istream& inStream, Student& studentObject){
    cout << "University: ";
    inStream >> studentObject.UniversityName;
    cout << "Registration number: ";
    inStream >> studentObject.RegistrationNumber;
    cout << "Proctor: ";
    inStream >> studentObject.proctor;
    return inStream;
}
ostream& operator<<(ostream& outStream, const Student& studentObject){
    outStream << "Student: \n";
    outStream << "\tUniversity: " << studentObject.UniversityName << "\n";
    outStream << "\tRegistration Number: " << studentObject.RegistrationNumber << "\n";
    outStream << "\tProctor: " << studentObject.proctor << "\n";
    return outStream;
}