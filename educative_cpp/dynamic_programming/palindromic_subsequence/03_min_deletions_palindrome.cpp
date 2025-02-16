#include <iostream>
#include <vector>
#include <string>

using namespace std;

int LongestPalindromicSubsequence(string s, int start, int end){
    if(start > end){
        return 0;
    }
    if(start == end){
        return 1;
    }
    if(s[start] == s[end]){
        return 2 + LongestPalindromicSubsequence(s, start + 1, end - 1);
    }
    int c1 = LongestPalindromicSubsequence(s, start + 1, end);
    int c2 = LongestPalindromicSubsequence(s, start, end - 1);
    return max(c1, c2);
}

int MinDeletions(string s){
    int length = s.length();
    return length - LongestPalindromicSubsequence(s, 0, length - 1);
}