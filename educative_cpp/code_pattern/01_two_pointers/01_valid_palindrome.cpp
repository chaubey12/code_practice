#include <iostream>
#include <vector>

using namespace std;

bool IsPalindrome(const string& inputString){
    int left=0;
    int right=inputString.length() - 1;
    while(left < right){
        if(inputString[left] != inputString[right]){
            return false;
        }
        left += 1;
        right -= 1;
    }
    return true;
}

int main(){
    if(IsPalindrome("ABCBA")){
        cout << "Is a palindrome"<<endl;
    }else{
        cout << "Is not a palindrome"<<endl;
    }
    return 0;
}