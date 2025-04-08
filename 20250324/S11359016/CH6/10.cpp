#include<iostream>
using namespace std;

class Weight{
    private:
        double weight;
    public:
        void setWeightPounds(double w){weight = w;}
        void setWeightKilograms(double w){weight = w * 2.21;}
        void setWeightOunces(double w){weight = w / 16;}

        double getWeightPounds(){return weight;}
        double getWeightKilograms(){return weight / 2.21;}
        double getWeightOunces(){return weight * 16.0;}
};

int main(){
    Weight w;
    double t;
    cin >> t;
    w.setWeightPounds(t);
    printf("%.2f\n", w.getWeightPounds());
    printf("%.2f\n", w.getWeightOunces());
    printf("%.2f\n", w.getWeightKilograms());
}