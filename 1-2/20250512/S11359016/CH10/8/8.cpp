#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class Television{
    private:
        string displayType;
        double dimension;
        string* connectivitySupport;
        int size;

    public:
        Television() : dimension(0), connectivitySupport(nullptr), size(0){}
        Television(string dt, double d, string* c, int s) : displayType(dt), dimension(d), size(s){
            if(s < 0) throw invalid_argument("Connectivity count must be nonnegative.");
            connectivitySupport = s > 0 ? new string[s] : nullptr;
            for(int i = 0; i < s; i++) connectivitySupport[i] = c[i];
        }
        Television(const Television& t) : displayType(t.displayType), dimension(t.dimension), size(t.size){
            connectivitySupport = size > 0 ? new string[size] : nullptr;
            for(int i = 0; i < size; i++) connectivitySupport[i] = t.connectivitySupport[i];
        }
        Television& operator=(const Television& other){
            if(this != &other){
                Television copy(other);
                swap(displayType, copy.displayType);
                swap(dimension, copy.dimension);
                swap(connectivitySupport, copy.connectivitySupport);
                swap(size, copy.size);
            }
            return *this;
        }
        ~Television(){delete[] connectivitySupport;}

        void setDisplayType(string t){displayType = t;}
        void setDimension(double d){dimension = d;}
        void setConnectivitySupport(string* c, int s){
            if(s < 0) throw invalid_argument("Connectivity count must be nonnegative.");
            string* replacement = s > 0 ? new string[s] : nullptr;
            for(int i = 0; i < s; ++i) replacement[i] = c[i];
            delete[] connectivitySupport;
            size = s;
            connectivitySupport = replacement;
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
    if(!(cin >> size) || size < 0) return 1;
    cin.ignore();

    string* conn = new string[size];
    for(int i = 0; i < size; i++){
        cout << "Connectivity " << i + 1 << ": ";
        getline(cin, conn[i]);
    }

    Television base(type, dim, conn, size);

    int n;
    cout << "Enter number of televisions: ";
    if(!(cin >> n)) return 1;
    cin.ignore();

    if(n < 0){delete[] conn; return 1;}
    vector<Television> tvs;
    tvs.reserve(n);
    for(int i = 0; i < n; i++){
        tvs.push_back(base); // Copies with Television's copy constructor.

        string ans;
        cout << "\nCustomize TV #" << i + 1 << "? (yes/no): ";
        getline(cin, ans);
        if(ans == "yes"){
            cout << "New display type: ";
            getline(cin, type);
            cout << "New dimension: ";
            cin >> dim;
            cout << "New number of connectivity options: ";
            if(!(cin >> size) || size < 0) return 1;
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

    return 0;
}
