#include <iostream>
#include <string>

using namespace std;

bool IsValidPalindrome(const string& str, int start, int end);

bool IsValidPalindromeSkip(const string& str){
    int start = 0, end = str.length() - 1;
    bool skip = true;
    while(start < end){
        if(str[start] != str[end]){
            if(skip){
                skip = !skip;
                if(IsValidPalindrome(str, start+1, end) == false && IsValidPalindrome(str, start, end-1) == false){
                    return false;
                }else{
                    return true;
                }
            }
            return false;
        }
        ++start, --end;
    }
    return true;
}

bool IsValidPalindrome(const string& str, int start, int end){
    while(start < end){
        if(str[start++] != str[end--]){
            return false;
        }   
    }
    return true;
}

int main(){
    string str = "RACEAECAIIR";
    if(IsValidPalindromeSkip(str)){
        cout << "VALID" << endl;
    }else{
        cout << "INVALID" << endl;
    }
    return 0;
}