#include <iostream>
#include <vector>
#include <string>

using namespace std;

int LongestPalindromeSubsequenceRecursive(vector<vector<int>>& lookup_table, string s, int start, int end){
    if(start > end){
        return 0;
    }
    if(start == end){
        return 0;
    }
    if(lookup_table[start][end] == 0){
        if(s[start] == s[end]){
            lookup_table[start][end] = 2 + LongestPalindromeSubsequenceRecursive(lookup_table, s, start + 1, end - 1);
        }else{
            int c1 = LongestPalindromeSubsequenceRecursive(lookup_table, s, start + 1, end);
            int c2 = LongestPalindromeSubsequenceRecursive(lookup_table, s, start, end - 1);
            lookup_table[start][end] = max(c1, c2);
        }
    }
    return lookup_table[start][end];
}

int LongestPalindromeSubsequence(string s){
    vector<vector<int>> lookup_table(s.length(), vector<int>(s.length(), 0));
    return LongestPalindromeSubsequenceRecursive(lookup_table, s, 0, s.length() - 1);
}

int MinDeletions(string s){
    return s.length() - LongestPalindromeSubsequence(s);
}