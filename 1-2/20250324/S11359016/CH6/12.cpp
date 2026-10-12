#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<stdexcept>
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
        string getItem(int index) const{if(index < 0 || index >= 3) throw out_of_range("Box index must be 0..2."); return box[index];}
        void setItem(int index, const string& newItem){if(index < 0 || index >= 3) throw out_of_range("Box index must be 0..2."); box[index] = newItem;}
        void display() const{for(string i : box) cout << i << " ";}
};

int main(){
    srand(time(0));
    string p[5];
    ifstream file("input.txt");

    for(int i = 0; i < 5; i++){
        if(!getline(file, p[i])){cerr << "Expected five produce items in input.txt.\n"; return 1;}
    }
    file.close();

    BoxOfProduce box(p[rand() % 5], p[rand() % 5], p[rand() % 5]);
    box.display();

    int cnt;
    cin >> cnt;
    for(int i = 0; i < cnt; i ++){
        int pos;
        string choice;
        if(!(cin >> pos >> choice)) return 1;
        bool allowed = false;
        for(const string& item : p) if(item == choice) allowed = true;
        if(pos < 0 || pos >= 3 || !allowed){cerr << "Choose index 0..2 and an item from the list.\n"; return 1;}
        box.setItem(pos, choice);
    }
    box.display();

}
