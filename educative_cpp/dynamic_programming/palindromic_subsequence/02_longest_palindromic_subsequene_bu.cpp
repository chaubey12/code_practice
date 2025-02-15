#include <iostream>
#include <vector>
#include <string>

using namespace std;

int LongestPalindromicSubsequence(string s){
    vector<vector<int>> lookup_table(s.length(), vector<int>(s.length(), 0));
    for(int i=0; i < s.length(); ++i){
        lookup_table[i][i] = 1;
    }
    for(int start_index=s.length(); start_index >= 0; start_index--){
        for(int end_index=start_index + 1; end_index < s.length(); end_index++){
            if(s[start_index] == s[end_index]){
                lookup_table[start_index][end_index] = 2 + lookup_table[start_index + 1][end_index - 1];
            }else{
                lookup_table[start_index][end_index] = max(lookup_table[start_index + 1][end_index], lookup_table[start_index][end_index - 1]);
            }
        }
    }
    return lookup_table[0][s.length() - 1];
}