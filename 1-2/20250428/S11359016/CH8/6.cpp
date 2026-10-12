#include<iostream>
#include<vector>
using namespace std;

class MyInteger{
    private:
        vector<int> num;
    public:
        MyInteger(){}
        MyInteger(int n){setNum(n);}

        void setNum(int n){
            num.clear();
            do{
                num.push_back(n % 10);
                n /= 10;
            } while(n != 0);
        }

        int getNum() const {
            int value = 0;
            for(int j = static_cast<int>(num.size()) - 1; j >= 0; --j)
                value = value * 10 + num[j];
            return value;
        }
        
        int operator [](int index){return index >= num.size() ? -1 : num[index];}
        friend istream& operator >>(istream& ip, MyInteger& n){
            int t;
            ip >> t;
            n.setNum(t);
            return ip;
        }
};

int main(){
    int index;
    MyInteger num;
    cin >> num;
    while(true){
        cin >> index;
        if(index == -1) break;
        else if(num[index] != -1) cout << num[index] << "\n";
        else cout << "out of range\n";
    }
    return 0;
}