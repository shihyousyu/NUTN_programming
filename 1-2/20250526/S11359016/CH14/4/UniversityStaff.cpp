#include<iostream>
#include<string>
#include"UniversityStaff.h"
using std::string;
using std::istream;
using std::ostream;
using std::cout;

UniversityStaff::UniversityStaff(){name = "no name yet";}
UniversityStaff::UniversityStaff(string theName){name = theName;}
UniversityStaff::UniversityStaff(const UniversityStaff& theObject){name = theObject.name;}

string UniversityStaff::getName() const{return name;}

UniversityStaff& UniversityStaff::operator=(const UniversityStaff& rtSide){name = rtSide.name;}
istream& operator>>(istream& inStream, UniversityStaff& staffObject){
    cout << "Enter the proctor of the student > ";
    inStream >> staffObject.name;
    return inStream;
}
ostream& operator<<(ostream& outStream, const UniversityStaff& staffObject){
    outStream << staffObject.name;
    return outStream;
}