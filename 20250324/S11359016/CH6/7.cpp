#include<iostream>
using namespace std;

class pizza{
    private:
        string type;
        string size;
        int cheese;
        int pepperoni;
    public:
        pizza(string t, string s, int c, int p) : type(t), size(s), cheese(c), pepperoni(p){}
        void setType(string t){type = t;}
        void setSize(string s){size = s;}
        void setCheese(int c){cheese = c;}
        void setPepper(int p){pepperoni = p;}

        string getType(){return type;}
        string getSize(){return size;}
        int getCheese(){return cheese;}
        int getPepperoni(){return pepperoni;}
        
        void outputDescription(){
            cout << "Type: " << type << "\n";
            cout << "Size: " << size << "\n";
            cout << "Cheese: " << cheese << "\n";
            cout << "Pepperoni: " << pepperoni << "\n";
        }
    
        double computePrice(){
            return ((size == "Small") ? 10 : (size == "Medium") ? 14 : 17) + 2 * (cheese + pepperoni);
        }
};

int main(){
    string t, s; int c, p;
    cin >> t >> s >> c >> p;
    pizza a(t, s, c, p);
    a.outputDescription();
    
    cout << "Total Price: $" << a.computePrice() << "\n";
}