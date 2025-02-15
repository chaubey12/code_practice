#include <iostream>
#include <string>
#include <vector>

using namespace std;

int LongestPalindromicSubsequenceRecursive(vector<vector<int>>& lookup_table, string s, int start_index, int end_index){
    if(start_index > end_index){
        return 0;
    }
    if(start_index == end_index){
        return 1;
    }
    if(lookup_table[start_index][end_index] == 0){
        if(s[start_index] == s[end_index]){
            lookup_table[start_index][end_index] = 2 + LongestPalindromicSubsequenceRecursive(lookup_table, s, start_index + 1, end_index - 1);
        }else{
            int c1 = LongestPalindromicSubsequenceRecursive(lookup_table, s, start_index + 1, end_index);
            int c2 = LongestPalindromicSubsequenceRecursive(lookup_table, s, start_index, end_index - 1);
            lookup_table[start_index][end_index] = max(c1, c2);
        }
    }
    return lookup_table[start_index][end_index];
}


int LongestPalindromicSubsequence(string s){
    vector<vector<int>> lookup_table(s.length(), vector<int>(s.length(), 0));
    return LongestPalindromicSubsequenceRecursive(lookup_table, s, 0, s.length()-1);
}