#include <iostream>
#include <vector>
#include <string>

using namespace std;

string Encoding(const string& s){
    string result;
    for(int i=1, count=1; i <= s.size(); ++i){
        if(i == s.size() || s[i] != s[i-1]){
            result += to_string(count) + s[i-1];
            count = 1;
        }else{
            ++count;
        }
    }
    return result;
}

string Decoding(const string& s){
    int count = 0;
    string result;
    for(const char& c : s){
        if(isdigit(c)){
            count = count*10 + c - '0';
        }else{
            result.append(count, c);
            count = 0;
        }
    }
    return result;
}

int main(){
    string code = "aaaabcccaa";
    cout << code << endl;
    cout << Encoding(code)<<endl;
    cout << Decoding(Encoding(code))<<endl;
    return 0;
}