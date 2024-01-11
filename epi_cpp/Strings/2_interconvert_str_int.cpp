#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string IntToString(int x){
    bool is_negative = false;
    if(x < 0){
        x = -x, is_negative=true;
    }
    string s;
    do{
        s += '0' + x%10;
        x /= 10;
    }while(x);
    if(is_negative){
        s += '-';
    }
    reverse(s.begin(), s.end());
    return s;
}

int StringToInt(const string& str){
    bool is_negative = (str[0] == '-');
    int result=0;
    for(int i = (str[0] == '-')? 1 : 0; i < str.length(); ++i){
        result = result*10 + (str[i] - '0');
    }
    return is_negative ? -result : result;
}

int main(){
    int x = -981;
    string s = IntToString(x);
    cout << s << endl;
    cout << StringToInt(s)<<endl;
    return 0;
}