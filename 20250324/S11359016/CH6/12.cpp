#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

class BoxOfProduce {
    private:
        string box[3];
    public:
        BoxOfProduce(){};
        BoxOfProduce(string item1, string item2, string item3){
            box[0] = item1;
            box[1] = item2;
            box[2] = item3;
        }
        string getItem(int index) const{return box[index];}
        void setItem(int index, const string& newItem){box[index] = newItem;}    
        void display() const{for(string i : box) cout << i << " ";}
};

int main(){
    srand(time(0));
    string p[5];
    ifstream file("input.txt");

    for(int i = 0; i < 5; i++) getline(file, p[i]);
    file.close();
    
    BoxOfProduce box(p[1], p[2], p[3]);
    box.display();

    int cnt;
    cin >> cnt;
    for(int i = 0; i < cnt; i ++){
        int pos;
        string choice;
        cin >> pos >> choice;
        box.setItem(pos, choice);
    }
    box.display();
    
}
