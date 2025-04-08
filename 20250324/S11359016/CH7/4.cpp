#include <iostream>
using namespace std;

class HotDogStand{
    private:
        int stand_id;
        int sold_today;
        static int total;
    public:
        HotDogStand(){};
        HotDogStand(int id, int sold) : stand_id(id), sold_today(sold){total += sold_today;}
        
        void justSold(){
            sold_today++;
            total++;
        }
        int getSold() const{return sold_today;}
        static int getTotal(){return total;}
};
int HotDogStand::total = 0;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    HotDogStand stand1(1, a), stand2(2, b), stand3(3, c);
    cin >> a >> b >> c;
    for(int i = 0; i < a; i ++) stand1.justSold();    
    for(int i = 0; i < b; i ++) stand2.justSold();    
    for(int i = 0; i < c; i ++) stand3.justSold();    

    cout << "Stand 1: " << stand1.getSold() << "\n";
    cout << "Stand 2: " << stand2.getSold() << "\n";
    cout << "Stand 3: " << stand3.getSold() << "\n";
    cout << "Total: " << HotDogStand::getTotal() << "\n";

    return 0;
}
