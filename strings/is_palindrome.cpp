#include <iostream>
#include <string>

using namespace std;

bool isPalindromic(const string& s){
    for(int i = 0, j = s.size() - 1; i < j; i++, j-- ){
        if(s[i] != s[j]){
            return false;
        }
    }
    return true;
}

int main(){
    const string s = "abcdcba";
    const string t = "abcdef";
    cout << isPalindromic(s)<< endl;
    cout << isPalindromic(t)<< endl;
    return 0;
}