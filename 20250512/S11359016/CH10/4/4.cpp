#include<bits/stdc++.h>
using namespace std;

class Subscriber{
    private:
        string name;
        int numChannels;
        string* channelList;
        void handleChannels(){
            numChannels = 0;

            string input;
            string s;
            getline(cin, s);
            stringstream ss(s);
            
            vector<string> temp;
		    while(ss >> input) temp.push_back(input);
		    numChannels = temp.size();

            channelList = new string[numChannels];
    		for(int i = 0; i < numChannels; i++) channelList[i] = temp[i];
        }
    public:
        Subscriber(){}
        Subscriber(string n){
            name = n;
            handleChannels();
        }
        Subscriber(const Subscriber& s){
            name = s.name;
            numChannels = s.numChannels;
            channelList = new string[numChannels];

            for(int i = 0; i < numChannels; i++) channelList[i] = s.channelList[i];
        }
        ~Subscriber(){delete [] channelList;}

        void setName(string n){name = n;}
        
        string getName() const{return name;}
        int getNumChannels() const{return numChannels;}
        string* getChannelList() const{return channelList;}

        void outputSubscriber(){
            cout << "\nSubscriber " << name << ":\n";
            cout << "\tnumChannels: " << numChannels << ".\n";
            cout <<"\tchennals: \n\t\t";
            for(int i = 0; i < numChannels; i ++) cout << channelList[i] << " ";
            cout << "\n";
        }
        void resetChannels(){
            delete [] channelList;
            channelList = nullptr;
            numChannels = 0;
        }
        Subscriber& operator =(const Subscriber& s){
            if(this != &s){
                delete [] channelList;
                name = s.name;
                numChannels = s.numChannels;
                channelList = new string[numChannels];
                for(int i = 0; i < numChannels; i++) channelList[i] = s.channelList[i];
            }
            return *this;
        }
};

int main(){
    string t;
    cout << "input name: ";
    cin >> t;
    cout << "input channels: ";
    Subscriber a(t);
    cout << "\n";
    a.outputSubscriber();
    cout << "Let Subscriber ____ = Subscriber " << a.getName() << ": ";
    cin >> t;
    Subscriber b;
    b = a;
    b.setName(t);
    b.outputSubscriber();
    cout << "reset Subscriber " << a.getName();
    a.resetChannels();
    a.outputSubscriber();
    return 0;
}