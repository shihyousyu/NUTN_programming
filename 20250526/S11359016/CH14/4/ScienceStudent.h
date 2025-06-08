#ifndef SCIENCESTUDENT_H
#define SCIENCESTUDENT_H

#include<iostream>
#include<string>
#include"Student.h"
using std::string;
using std::istream;
using std::ostream;
using std::cout;

class ScienceStudent : public Student{
    private:
        string scienceDiscipline;
        string course;
    public:
        ScienceStudent();
        ScienceStudent(string d, string c);
        ScienceStudent(const ScienceStudent& t);

        void setScienceDiscipline(string d);
        void setCourse(string c);
        
        string getScienceDiscipline() const;
        string getCourse() const;
        
        ScienceStudent& operator=(const ScienceStudent& rtSide);
        friend istream& operator>>(istream& inStream, ScienceStudent& scienceStudentObject);
        friend ostream& operator<<(ostream& outStream, const ScienceStudent& scienceStudentObject);
    };

#endif