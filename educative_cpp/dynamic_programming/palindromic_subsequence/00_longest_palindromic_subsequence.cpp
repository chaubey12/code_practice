#include <iostream>
#include <vector>
#include <string>

using namespace std;

int LongestPalindrominSubsequenceRecursive(string s, int start_index, int end_index){
    if(start_index > end_index){
        return 0;
    }
    if(start_index == end_index){
        return 1;
    }
    if(s[start_index] == s[end_index]){
        return 2 + LongestPalindrominSubsequenceRecursive(s, start_index+1, end_index-1);
    }
    return max(LongestPalindrominSubsequenceRecursive(s, start_index+1, end_index),
               LongestPalindrominSubsequenceRecursive(s, start_index, end_index-1));
}

int LongestPalindromicSubsequence(string s){
    int length = s.length();
    return LongestPalindrominSubsequenceRecursive(s, 0, length - 1);
}