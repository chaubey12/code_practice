#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string NextNumber(const string& s){
    string ret;
    for(int i = 0; i < s.size(); ++i){
        int count = 1;
        while(i+1 < s.size() && s[i] == s[i+1]){
            i++, ++count;
        }
        ret += to_string(count) + s[i];
    }
    return ret;
}


string LookAndSay(int n){
    string s = "1";
    for(int i=1; i < n; ++i){
        s = NextNumber(s);
    }
    return s;
}

int main(){
    cout << LookAndSay(10)<<endl;
    return 0;
}