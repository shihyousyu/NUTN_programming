#include <iostream>
#include <vector>
using namespace std;

class MyInteger{
    private:
        vector<int> num;
        int value;
    public:
        MyInteger() : value(0){setNum(0);}
        MyInteger(int n){setNum(n);}
        void setNum(int n){
            value = n;
            num.clear();
            long long magnitude = n;
            if(magnitude < 0) magnitude = -magnitude;
            do{
                num.push_back(static_cast<int>(magnitude % 10));
                magnitude /= 10;
            }while(magnitude != 0);
        }
        int getNum() const{return value;}
        int operator[](int index) const{
            return index < 0 || static_cast<size_t>(index) >= num.size() ? -1 : num[index];
        }
        friend istream& operator>>(istream& ip, MyInteger& n){
            int value;
            if(ip >> value) n.setNum(value);
            return ip;
        }
};

int main(){
    int index;
    MyInteger num;
    if(!(cin >> num)) return 1;
    while(cin >> index && index != -1){
        if(num[index] != -1) cout << num[index] << "\n";
        else cout << "out of range\n";
    }
    return 0;
}
