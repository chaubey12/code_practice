#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

bool CanFormPalindrome(const string& str){
    unordered_map<char, int> charFrequencies;
    for(char ch :str){
        ++charFrequencies[ch];
    }
    int oddCount = 0;
    for(auto entry : charFrequencies){
        if((entry.second % 2) == 1){
            if((++oddCount) > 1){
                return false;
            }
        }
    }
    return true;
}

int main(){
    string str = "foobaraboo";
    if(CanFormPalindrome(str)){
        cout << "CAN FORM PALINDROME"<<endl;
    }else{
        cout << "CANNOT FORM PALINDROME"<<endl;
    }
    return 0;
}