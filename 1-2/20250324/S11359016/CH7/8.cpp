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
            cin >> grade;
            if (grade == -1) break;
            grades.push_back(grade);
        }
    }

    void display() const{
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
