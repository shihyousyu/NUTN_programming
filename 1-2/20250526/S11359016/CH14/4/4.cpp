#include<iostream>
#include<string>
#include"ScienceStudent.h"
using namespace std;

int main(){
    ScienceStudent Sstudent;
    cin >> Sstudent;
    cout << Sstudent;

    UniversityStaff staff("Professor");
    Student student("NUTN", 123, staff);
    student.setRegistrationNumber(456);
    cout << student.getRegistrationNumber() << "\n";
    
    Student copied(student), assigned;
    assigned = student;
    cout << copied << assigned;
    return 0;

}