#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class gradeHistogram{
private:
    vector<int> grades;
public:
    gradeHistogram(){};
    void setGrades(){
        int grade;
        while(true){
            if(!(cin >> grade)) break;
            if (grade == -1) break;
            if(grade < 0){ cerr << "Grades must be nonnegative.\n"; continue; }
            grades.push_back(grade);
        }
    }

    void display() const{
        if(grades.empty()){ cout << "No grades entered.\n"; return; }
        int maxGrade = *max_element(grades.begin(), grades.end());
        vector<int> histogram(maxGrade + 1, 0);
        for(int grade : grades) histogram[grade]++;
        for(int i = 0; i <= maxGrade; i++) {
            cout << i << ": ";
            for(int j = 0; j < histogram[i]; j++) cout << "*";
            cout << " (" << histogram[i] << ")\n";
        }
    }
};

int main() {
    gradeHistogram g;
    g.setGrades();
    g.display();
    return 0;
}
