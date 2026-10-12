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

        string result;
        for(size_t pos = 0; pos < s.size();) {
            if(!isalpha(s[pos])){
                result += s[pos++];
                continue;
            }
            size_t end = pos;
            while(end < s.size() && isalpha(s[end])) ++end;
            if(end - pos == 4) result += isupper(s[pos]) ? "Love" : "love";
            else result += s.substr(pos, end - pos);
            pos = end;
        }
        cout << result << "\n";
    }
}
