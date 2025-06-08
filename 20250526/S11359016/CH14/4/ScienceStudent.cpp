#include<iostream>
#include<string>
#include"Student.h"
#include"ScienceStudent.h"
using std::string;
using std::istream;
using std::ostream;
using std::cout;

ScienceStudent::ScienceStudent() : scienceDiscipline(""), course(""){}
ScienceStudent::ScienceStudent(string d, string c) : scienceDiscipline(d), course(c){}
ScienceStudent::ScienceStudent(const ScienceStudent& t){
    scienceDiscipline = t.scienceDiscipline;
    course = t.course;
    UniversityName = t.UniversityName;
    RegistrationNumber = t.RegistrationNumber;
    proctor = t.proctor;
}

void ScienceStudent::setScienceDiscipline(string d){scienceDiscipline = d;}
void ScienceStudent::setCourse(string c) {course = c;}

string ScienceStudent::getScienceDiscipline() const{return scienceDiscipline;}
string ScienceStudent::getCourse() const{return course;}

ScienceStudent& ScienceStudent::operator=(const ScienceStudent& rtSide){
    scienceDiscipline = rtSide.scienceDiscipline;
    course = rtSide.course;
    UniversityName = rtSide.UniversityName;
    RegistrationNumber = rtSide.RegistrationNumber;
    proctor = rtSide.proctor;
}

istream& operator>>(istream& inStream, ScienceStudent& scienceStudentObject){
    cout << "University: ";
    inStream >> scienceStudentObject.UniversityName;
    cout << "Registration number: ";
    inStream >> scienceStudentObject.RegistrationNumber;
    cout << "Proctor: ";
    inStream >> scienceStudentObject.proctor;
    cout << "Science discipline: ";
    inStream >> scienceStudentObject.scienceDiscipline;
    cout << "Undergraduate or Postgraduate course: ";
    inStream >> scienceStudentObject.course;
    return inStream;
}

ostream& operator<<(ostream& outStream, const ScienceStudent& scienceStudentObject){
    outStream << "Science Student: " << "\n";
    outStream << "\tUniversity: " << scienceStudentObject.UniversityName << "\n";
    outStream << "\tRegistration Number: " << scienceStudentObject.RegistrationNumber << "\n";
    outStream << "\tProctor: " << scienceStudentObject.proctor << "\n";
    outStream << "\tScience Discipline: " << scienceStudentObject.scienceDiscipline << "\n";
    outStream << "\tCourse: " << scienceStudentObject.course << "\n";
    return outStream;
}