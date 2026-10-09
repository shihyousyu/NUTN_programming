#include<iostream>
using namespace std;

class Pizza{
    private:
        string type;
        string size;
        int cheese;
        int pepperoni;
    public:
        Pizza(){};
        Pizza(string t, string s, int c, int p) : type(t), size(s), cheese(c), pepperoni(p){}
        
        void setType(string t){type = t;}
        void setSize(string s){size = s;}
        void setCheese(int c){cheese = c;}
        void setPepper(int p){pepperoni = p;}

        string getType() const{return type;}
        string getSize() const{return size;}
        int getCheese() const{return cheese;}
        int getPepperoni() const{return pepperoni;}
        
        void outputDescription() const{
            cout << "Type: " << type << "\n";
            cout << "Size: " << size << "\n";
            cout << "Cheese: " << cheese << "\n";
            cout << "Pepperoni: " << pepperoni << "\n";
        }
        double computePrice() const{
            return ((size == "Small") ? 10 : (size == "Medium") ? 14 : 17) + 2 * (cheese + pepperoni);
        }
};

int main(){
    string t, s; int c, p;
    cin >> t >> s >> c >> p;
    Pizza a(t, s, c, p);
    a.outputDescription();
    cout << "Total Price: $" << a.computePrice() << "\n";
}