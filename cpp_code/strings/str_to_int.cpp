#include <iostream>
#include <string>

using namespace std;

int StringToInt(string s){
    bool is_negative = s[0] == '-';
    int result = 0;
    for(int i = s[0] == '-' ? 1 : 0; i < s.length(); i++){
        int digit = s[i] - '0';
        result = result*10 + digit;
    }
    return is_negative ? -result : result;
}

int main(){
    string x = "12345";
    string y = "-1234";
    cout << StringToInt(x) << endl;
    cout << StringToInt(y) << endl;
    return 0;
}