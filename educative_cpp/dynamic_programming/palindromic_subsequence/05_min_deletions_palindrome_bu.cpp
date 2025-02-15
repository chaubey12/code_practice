#include <iostream>
#include <vector>
#include <string>

using namespace std;

int LongestPalindromicSubsequence(string s){
    vector<vector<int>> lookup_table(s.length(), vector<int>(s.length(), 0));
    for(int i=0; i < s.length(); ++i){
        lookup_table[i][i] = 1;
    }
    for(int s = s.length() - 1; start >= 0; start--){
        for(int end = start + 1; end < s.length(); end++){
            if(s[start] == s[end]){
                lookup_table[start][end] = 2 + lookup_table[start + 1][end - 1];
            }else{
                lookup_table[start][end] = max(lookup_table[start][end - 1], lookup_table[start + 1][end]);
            }
        }
    }
    return lookup_table[0][s.length() - 1];
}

int MinDeletions(string s){
    return s.length() - LongestPalindromicSubsequence(s);
}