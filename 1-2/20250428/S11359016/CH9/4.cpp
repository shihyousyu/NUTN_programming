#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string replaceFourLetterWords(const string& line){
    string result;
    for(size_t pos = 0; pos < line.size();){
        if(!isalpha(static_cast<unsigned char>(line[pos]))){
            result += line[pos++];
            continue;
        }
        size_t end = pos;
        while(end < line.size() && isalpha(static_cast<unsigned char>(line[end]))) ++end;
        if(end - pos == 4)
            result += isupper(static_cast<unsigned char>(line[pos])) ? "Love" : "love";
        else result += line.substr(pos, end - pos);
        pos = end;
    }
    return result;
}

int main(){
    string line;
    while(getline(cin, line) && line != "quit")
        cout << replaceFourLetterWords(line) << "\n";
    return 0;
}
