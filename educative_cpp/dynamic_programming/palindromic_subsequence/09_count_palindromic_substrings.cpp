#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

bool CheckPalindrome(string s, int start, int end){
    if(start > end){
        return true;
    }
    if(s[start] != s[end]){
        return false;
    }
    return CheckPalindrome(start, start + 1, end - 1);
}

int CountPalindromicSubstringRecursive(string s, int start, int end){
    if(start >= end){
        return 0;
    }
    int psCount = 0;
    if(CheckPalindrome(s, start, end)){
        psCount = 1 + CountPalindromicSubstringRecursive(s, start + 1, end)
                    + CountPalindromicSubstringRecursive(s, start, end - 1)
                    - CountPalindromicSubstringRecursive(s, start + 1, end - 1);
        return psCount;
    }else{
        psCount = CountPalindromicSubstringRecursive(s, start + 1, end) + CountPalindromicSubstringRecursive(s, start, end - 1);
        return psCount;
    }

}

int CountPalindromicSubstrings(string s){
    return s.length() + CountPalindromicSubstringRecursive(s, 0, s.length() - 1);
}