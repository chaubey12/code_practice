#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrome(const string& str){
    int left = 0, right = str.length() - 1;
    while(left < right){
        if(str[left++] != str[right--]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<string> input = {"RACEAAR", "RACECAR"};
    for(auto ip : input){
        if(IsPalindrome(ip)){
            cout << "Valid Palindrome" << endl;
        }else{
            cout << "Not Palindrome" << endl;
        }
    }
    return 0;
}