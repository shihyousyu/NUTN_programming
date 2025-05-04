#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

int main(){
    string s;
    while(true){
        getline(cin, s);
        if(s == "quit") break;

        stringstream ss(s);
        vector<string> t;
        string word;

        while(ss >> word){
            int cnt = 0;
            for(char c : word) if(isalpha(c)) cnt++;
            if(cnt == 4){
                string suffix = "";
                while(!word.empty() && !isalpha(word.back())){
                    suffix = word.back() + suffix;
                    word.pop_back();
                }
                if(isupper(word[0])) word = "Love" + suffix;
                else word = "love" + suffix;
            }
            t.push_back(word);
        }

        if(!t.empty()){
            cout << t[0];
            for(int i = 1; i < t.size(); i++) cout << " " << t[i];
        }
        cout << "\n";
    }
}
