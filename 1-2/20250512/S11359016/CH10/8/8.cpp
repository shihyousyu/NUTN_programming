#include <iostream>
#include <string>
using namespace std;

class Television{
    private:
        string displayType;
        double dimension;
        string* connectivitySupport;
        int size;

    public:
        Television(){connectivitySupport= new string[0];}
        Television(string dt, double d, string* c, int s) : displayType(dt), dimension(d), size(s){
            connectivitySupport = s > 0 ? new string[s] : nullptr;
            for(int i = 0; i < s; i++) connectivitySupport[i] = c[i];
        }
        Television(const Television& t) : displayType(t.displayType), dimension(t.dimension), size(t.size){
            connectivitySupport = size > 0 ? new string[size] : nullptr;
            for(int i = 0; i < size; i++) connectivitySupport[i] = t.connectivitySupport[i];
        }
        ~Television(){delete[] connectivitySupport;}

        void setDisplayType(string t){displayType = t;}
        void setDimension(double d){dimension = d;}
        void setConnectivitySupport(string* c, int s){
            delete[] connectivitySupport;
            size = s;
            connectivitySupport = s > 0 ? new string[s] : nullptr;
            for(int i = 0; i < s; i++) connectivitySupport[i] = c[i];
        }

        string getDisplayType() const{return displayType;}
        double getDimension() const{return dimension;}
        string* getConnectivitySupport() const{return connectivitySupport;}
        int getConnectivitySize() const{return size;}
};

int main() {
    string type;
    double dim;
    int size;

    cout << "Enter default display type: ";
    getline(cin, type);
    cout << "Enter default dimension: ";
    cin >> dim;
    cout << "Enter number of connectivity options: ";
    cin >> size;
    cin.ignore();

    string* conn = new string[size];
    for(int i = 0; i < size; i++){
        cout << "Connectivity " << i + 1 << ": ";
        getline(cin, conn[i]);
    }

    Television base(type, dim, conn, size);

    int n;
    cout << "Enter number of televisions: ";
    cin >> n;
    cin.ignore();

    Television* tvs = new Television[n];
    for(int i = 0; i < n; i++){
        tvs[i] = base;

        string ans;
        cout << "\nCustomize TV #" << i + 1 << "? (yes/no): ";
        getline(cin, ans);
        if(ans == "yes"){
            cout << "New display type: ";
            getline(cin, type);
            cout << "New dimension: ";
            cin >> dim;
            cout << "New number of connectivity options: ";
            cin >> size;
            cin.ignore();

            string* newConn = new string[size];
            for(int j = 0; j < size; j++){
                cout << "Connectivity " << j + 1 << ": ";
                getline(cin, newConn[j]);
            }
            tvs[i].setDisplayType(type);
            tvs[i].setDimension(dim);
            tvs[i].setConnectivitySupport(newConn, size);
            delete[] newConn;
        }
    }
    delete[] conn;
    delete[] tvs;
    return 0;
}