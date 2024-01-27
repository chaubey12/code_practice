#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsPalindrome(const string& s){
    for(int i=0, j=s.length() - 1; i < j; ++i, --j){
        if(s[i] != s[j]){
            return false;
        }
    }
    return true;
}

int main(){
    string s = "abcdcbad";
    if(IsPalindrome(s)){
        cout << "PALINDROME"<<endl;
    }else{
        cout << "NOT A PALINDROME"<<endl;
    }
    return 0;
}