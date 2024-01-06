#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

string SnakeString(const string& s){
    string result;
    for(int i=1; i < s.size(); i += 4){
        result += s[i];
    }
    result += '\n';
    for(int i=0; i < s.size(); i += 2){
        result += s[i];
    }
    result += '\n';
    for(int i = 3; i < s.size(); i += 4){
        result += s[i];
    }
    return result;
}

int main(){
    string str ="Hello World";
    cout << SnakeString(str) << endl;
    return 0;
}