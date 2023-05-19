#include <iostream>
#include <string>

using namespace std;

string IntToString(int x){
    bool is_negative = false;
    if(x < 0){
        x = -x, is_negative = true;
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

int main(){
    int x = 12345;
    int y = -1234;
    cout << IntToString(x) << endl;
    cout << IntToString(y) << endl;
    return 0;
}