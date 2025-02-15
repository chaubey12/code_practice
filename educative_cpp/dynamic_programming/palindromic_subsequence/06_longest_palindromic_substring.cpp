#include <iostream>
#include <vector>
#include <string>

using namespace std;

int FindLongestPalindromicSubstringRecursion(string s, int start, int end){
    if(start == end){
        return 1;
    }
    if(s[start] == s[end]){
        int substringLength = end - start + 1;
        if(substringLength == 2){
            return 2;
        }
        if(substringLength == 2 + FindLongestPalindromicSubstringRecursion(s, start + 1, end - 1)){
            return substringLength;
        }
    }
    return max(FindLongestPalindromicSubstringRecursion(s, start + 1, end), FindLongestPalindromicSubstringRecursion(s, start, end - 1));
}

int FindLongestPalindromicSubstring(string s){
    return FindLongestPalindromicSubstringRecursion(s, 0, s.length() - 1);
}