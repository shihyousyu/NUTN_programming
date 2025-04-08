#include<iostream>
using namespace std;

class Money{
    private:
        int dollar;
        int cent;
    public:
        Money(int d, int c) : dollar(d), cent(c){};
        
        void setDollar(int d){dollar = d;}
        void setCent(int c){cent = c;}

        int getDollar() const{return dollar;}
        int getCent() const{return cent;}

        int getAmount() const{return (dollar + cent / 100.0);}
};

int main(){
    int d1, c1;
    int d2, c2;
    
    cin >> d1 >> c1;
    cin >> d2 >> c2;
    
    Money m1(d1, c1);
    Money m2(d2, c2);

    cout << m1.getAmount() << "\n";
    cout << m2.getAmount() << "\n";

    return 0;
}